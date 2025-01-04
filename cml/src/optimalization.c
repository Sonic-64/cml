#include "optimalization.h"



particle_swarm *swarm_alloc(int num_particles,int lower_limit,int upper_limit,int num_arguments){
particle_swarm *alloc = calloc(1,sizeof(particle_swarm));
alloc->particles = calloc(num_particles,sizeof(particle));
alloc->num_particles = num_particles;
alloc->best_position = calloc(num_arguments,sizeof(double));
alloc->best_values = calloc(num_particles,sizeof(double));
alloc->num_values = num_arguments;
for (int j = 0 ; j < num_particles ; j++ ){
alloc->particles[j].position = particle_random_position(num_arguments,lower_limit,upper_limit);
alloc->best_values[j] = HUGE_VAL;
}
return alloc;
}


void swarm_free(particle_swarm *alloc){

for(int i = 0 ; i < alloc->num_particles ; i++){
    particle_free(&alloc->particles[i]);
}
free(alloc->particles);
free(alloc->best_position);
free(alloc->best_values);
free(alloc);
}


void particle_free(particle *particle){
    free(particle->best_position);
    free(particle->position);
    free(particle->velocity);
}


void particle_speed(particle *particle,double *best,int num_values){
for(int i = 0 ; i < num_values ; i++){
    particle->velocity[i] = (INERTIA * particle->velocity[i]) + ((particle->best_position[i] - particle->position[i]) * COGNITIVE_COEFFICENT) + ((best[i]-particle->position[i])*SOCIAL_COEFFICENT);
    particle->position[i] += particle->velocity[i];
}
}


double *particle_random_position(int num_values,int lower_limit,int upper_limit){
    double *values = malloc(num_values * sizeof(double));
    for(int i = 0 ; i < num_values ; i++){
        values[i] = (rand() / (double)RAND_MAX) * (upper_limit - lower_limit) + lower_limit;
        
    }
    return values;
}


double *particle_optimalization(int num_particles,int num_iterations,int lower_limit,int upper_limit,int num_arguments, double(*f)(double*,int)){
particle_swarm *swarm = swarm_alloc(num_particles,lower_limit,upper_limit,num_arguments);

int j;
int i = 0;
double current_best = HUGE_VAL;
double current = 0;

while(1){
    for( j = 0 ; j < num_particles ; j++){
      current = f(swarm->particles[j].position,swarm->num_values);
      if(current<current_best){
        current_best = current;
        memcpy(swarm->best_position,&swarm->particles[j].position,swarm->num_values * sizeof(double));
      }
      if(current<swarm->best_values[j]){
      swarm->best_values[j] = current;
      memcpy(&swarm->particles[j].best_position,&swarm->particles[j].position,swarm->num_values * sizeof(double));
      }
    particle_speed(&swarm->particles[j],swarm->best_position,swarm->num_values);
       
    }
    i++;
    if(i==num_iterations )
    break;
}
double *alltime_best = malloc(swarm->num_values*sizeof(double));
memcpy(alltime_best,swarm->best_position,swarm->num_values * sizeof(double));
swarm_free(swarm);
return alltime_best;

}


