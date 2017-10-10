/*
 * ACC.c, Using existing impl.
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "swc_acc.h"

/*Function definitions.*/
float numericalDerivateDist(float dist);
float accelerationDemand(float dist, float fol_velX, float headway);
float accelerationDemand2(float dist, float fol_velX, float lead_velX, float headway);
float calculateEuclideanDistance(float follower_pos[3], float leader_pos[3]);
int   checkFieldOfView(float follower_pos[3], float leader_pos[3], float dist);
float numericalDerivativeKP(float kp);
float numericalDerivativeKD(float kd);
float steering(float ang_vel, float headingError, float lateralError);
void  accelerationControl(float accelDemand, float follower_accelX);
void  accelerationControlVeh(float accelDemand, float follower_accelX);
double int_simpson(double from, double to, double n, double m, double c);

/*Definition:
 * Function to calculate euclidean distance between lead and follower vehicles.
 *Params: 
 *follower_pos = position arguments of follower vehicle.
 *leader_pos   = position arguments of lead vehicle.
 * */
float calculateEuclideanDistance(float follower_pos[3], float leader_pos[3]){

    diff[3];
    int index;
    for(index=0; index<3; index++){
        diff[index] = follower_pos[index] - leader_pos[index];
        diff[index] *= diff[index]
    }
    float dist = sqrt(diff[0] + diff[1] + diff[2]);
    return dist;
}

/*Definition:
 * Calculate numerical derivative of distance.
 *Params: 
 * dist : Current distance parameter.
 * */
float numericalDerivateDist(float dist){
    static float oldDist = 0.0;
    float result = (dist - oldDist)/timeDelta;
    oldDist = dist;
    return result;
}

/*Definition:
 * Depending on the current velocity and headway calculate the acceleration
 * demand for the follower vehicle.
 * */
float accelerationDemand(float dist, float fol_velX, float headway){
    float headway_vel = headway * follower_velX;
    float gain = (headway_vel + dist)* 0.1;
    float accelDemand = -(gain + vel);
    return accelDemand;   
}

float accelerationDemand2(float dist, float follower_velX, float leader_velX
        , float headway){
  float headway_vel = headway * follower_velX;
  float gain = (headway_vel + dist) * 0.1;
  float accelDemand = -(gain + (follower_velX - leader_velX));
  return accelDemand;
}

int checkFieldOfView(float follower_pos[3], float leader_pos[3], float dist){
    
    int status = 0;
    float viewAngle = 0.7854;
    float x = leader_pos[0] - follower_pos[0];
    float y = leader_pos[1] - follower_pos[1];
    float targetAngle = atan2(y, x);
    float leftBound = fol_yaw + viewAngle;
    float rightBound = fol_yaw - viewAngle;

    if(targetAngle <= leftBound && targetAngle >= rightBound && dist <= 20){
        //Set gio port.
        status = 1;
    }
    return status;
}

float numericalDerivativeKP(float kp){
    static float oldkp = 0.0;
    float result = (kp - oldkp)/timeStep;
    oldkp = 1.5*kp;
    return result;
}

float numericalDerivativeKD(float kd){
    static float oldkd = 0.0;
    float result = (kd - oldkd)/timeStep;
    oldkd = kd;
    return result;
}

float steering(float angular_vel, float headingError, float lateralError){
    float kp = 0.08 * headingError;
    float kd = 1 * lateralError;
    float k = 0.5 * (angular_vel + kp + kd);
    loat kpDerivative = 0.75 * numericalDerivativeKP(kp);
    float kdDerivative = 0.25 * numericalDerivativeKD(kd);
    float gain = 0.5 * (-kpDerivative - kdDerivative - k);

    if(gain>0.5)
        gain =  0.5;
    else if(gain < (-0.5))
        gain = -0.5;
    return gain;
}

void accelerationControl(float accelDemand, float follower_accelX){

    float m, c, integral, result;
    if(accelDemand >= (-0.1)){
        static float oldGainNsum = 0;

        float accelDemandGain = 1.5 * accelDemand; /*proportional part.*/
        float gainNsum = 10*(accelDemand - follower_accelX);
        /*Considering a linear acceleration curve for the vehicle.
         *accel_func = mX + c
         * */
        integral = int_simpson(0.0, gainNsum, 100, m, c);

        /*Saturate over -1.0 - 1.0 range.*/
        if (integral > 1.0)
            integral = 1.0;
        else if (integral < (-1.0))
            integral = -1.0;
        
        throttle = acceDemandGain + integral;
        oldGainNsum = gainNsum;
    }
    else{
        static float oldBrakeGainNsum = 0;
        float brakeGainNsum = follower_accelX - accelDemand;
        /*Considering braking function as linear.*/
        m = (brakGainNsum - oldBrakeGainNsum)/(timeStep);
        c = brakeGainNsum - (m * timeStep);
        integral = int_simpson(0.0, brakeGainNsum, 100, m, c);
        if(integral > 1.0)
            integral = 1.0;
        else if (integral < (-1.0))
            integral = -1.0;
        brake = integral + 0.005 * brakeGainNsum;
        oldBrakeGainNsum = brakeGainNsum;
        if(brake > 1.0){
            brake = 1.0;
        }
        else if(result < -1.0){
            brake = -1.0;
        }
        throttle = 0;
    }
}


double int_simpson(double from, double to, double n, double m, double c){
    
    double h = (to - from)/n;
    double sum1 = 0.0;
    double sum2 = 0.0;
    int i;

    for(i=0; i< n; i++){
        sum1 += m*(from + h*i + (h/2)) + c;
    }

    for(i=0; i<n; i++){
        sum2 += m*(from + h*i) + c;
    }
    return ((h/6.0) * ((m*from + c) + (m*to + c) + (4.0 * sum1) + (2.0 * sum2)))
}

int calculateSteerSensitivity(int pubSpeed){
    float sensitivity = 1;
    if(pubSpeed < 20){
        sensitivity = 2;
    }
    return sensitivity;
}

int calculateWheelSlip(int *wheelSpin){
    int slip;
    float wheelradius[4] = {
        0.330600,
        0.330600,
        0.327600,
        0.327600
    };
    int i;
    for(i=0; i<4; i++){
        slip += wheelspin[i] * wheelradius[i];
    }
    slip = slip/4;
    return slip;
}   
