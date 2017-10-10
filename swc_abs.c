#include "swc_abs.h"
#include <math.h>
/*Implementation of basic derivative based ABS Setup*/
#define NO_WHEEL 4
#define EPS 0.45
double active_friction[NO_WHEEL];
double active_slip_rate[NO_WHEEL];
double angular_speed;
double generic_slip;
unsigned int friction_calc;

double desired_slip = 0.2; // Ideal slip ratio for maximum braking performance.
double wheel_radius = 0.352;
double m = 493;
double J = 1.13;
double TB = 1500;

double c1 = 1.2801;
double c2 = 23.99;
double c3 = 0.52;
double c4 = 0.03;
double V0 = (5*96.5606)/18;
double W0 = V0/wheel_radius;
absbrake_wheeldata_t wheel_data[NO_WHEEL];

void ABS_component_initialize(absbrake_wheeldata_t* ptwheelspeed){
    int i;
    for(i = 0; i < NO_WHEEL; i++){
        wheel_data[i].angular_speed = 0.0;
        wheel_data[i].wheel_radius = 0.0;
        active_friction[i] = 1.0; // Ideal slip value for a stationary vehicle.
        active_slip_rate[i] = 0.2; //Ideal slip ratio based on friction curve.
    }
    friction_calc = eCALCULATE;
}

//For each independent wheel update data.
void ABS_update_wheel_data(unsigned int state){
    int i;
    if (state == eFULL_SERVICE)
    {
        for (i = 0; i < NO_WHEEL; i++)
        {
            wheel_data[i].angular_speed = 12; // Dummy value.
        }
    }
    else{
        wheel_data[0].angular_speed = 12;
    }
}

//Slip calculated as: 1.0 - u1/u2 + (u2 == 0)*eps;
void ABS_slip_calculator(unsigned int delta, unsigned int state){
    int i;
    if(state == eFULL_SERVICE){
        for(i = 0; i < NO_WHEEL; i++){
          if(angular_speed){
              active_slip_rate[i] = (1 - wheel_data[i].angular_speed/angular_speed);
          }
          else{
              active_slip_rate[i] = 1 - EPS;
          }
        }
    }
    else{
        active_slip_rate[0] = (1 - wheel_data[0].angular_speed/angular_speed);
    }
}

static void ABS_friction_calculator(unsigned int state)
{
    int i, j;
    if (state == eFULL_SERVICE)
    {
        for (i = 0; i < NO_WHEEL; i++)
        {
            if (active_slip_rate[i] > 0.5)
                active_friction[i] = friction_table[11][1];
            else
            {
                for (j = 0; j < 12; j++)
                {
                    if (active_slip_rate[i] < friction_table[j][0])
                    {
                        active_slip_rate[i] = friction_table[j][1];
                        break;
                    }
                }
            }
        }
    }
    else
    {
        if (active_slip_rate[0] > 0.5)
            active_friction[0] = friction_table[11][1];
        else
        {
            for (j = 0; j < 12; j++)
            {
                if (active_slip_rate[0] < friction_table[j][0])
                {
                    active_slip_rate[0] = friction_table[j][1];
                    break;
                }
            }
        }
    }
}

static void ABS_calculate_wheel_speed(unsigned int state){

}

// Main function to do the ABS control functionality.
void ABS_update(unsigned int state){
    ABS_slip_calculator();
    ABS_friction_calculator();
}
