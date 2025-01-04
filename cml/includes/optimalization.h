#ifndef OPTIMALIZATION_H
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define INERTIA 0.3
#define COGNITIVE_COEFFICENT 0.2
#define SOCIAL_COEFFICENT 0.2
typedef struct particle{
    double* position;
    double* velocity;
    double* best_position;
}particle;
typedef struct particle_swarm{
    int num_values;
    int num_particles;
    particle *particles;
    double *best_position;
    double *best_values;

}particle_swarm;
particle_swarm *swarm_alloc(int num_particles,int lower_limit,int upper_limit,int num_arguments);
void swarm_free(particle_swarm *alloc);
void particle_free(particle *particle);
void particle_speed(particle *particle,double *best,int num_values);
double *particle_random_position(int num_values,int lower_limit,int upper_limit);
double *particle_optimalization(int num_particles,int num_iterations,int lower_limit,int upper_limit,int num_arguments, double(*f)(double*,int));
#define OPTIMALIZATION_H
#endif