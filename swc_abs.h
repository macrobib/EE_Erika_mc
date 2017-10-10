

#ifndef ABS_H_
#define ABS_H_
/***Constant definition for the variables ****/
#define faspeed float
#define fradius  float
/***Constant definition ends***/

enum friction_source{
    eLOOKUP,
    eCALCULATE
};

enum service_states{
    eFULL_SERVICE, //Individual braking for wheels.
    eLIMITED_SERVICE //Generic braking for all wheels.
};

typedef struct _absbrake_wheeldata_t{
    faspeed angular_speed;
    fradius wheel_radius;
}absbrake_wheeldata_t;

//Static table defining the friction value for different wheel slip ratios.
double friction_table[12][2] =
{
    {   0.0,    0.0 },
    {   0.05,   0.4 },
    {   0.1,    0.8 },
    {   0.150,  0.97},
    {   0.2,    1.0 },
    {   0.25,   0.98},
    {   0.3,    0.96},
    {   0.35,   0.94},
    {   0.40,   0.92},
    {   0.45,   0.9 },
    {   0.5,    0.88},
    {   0.55,   0.855}
};

#endif /* ABS_H_ */
