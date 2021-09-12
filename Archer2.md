# Running MPI in Archer2 Super Computer

## In archer2 you can compile a program using

```CC test.cpp```

## Batch job
```
#!/bin/bash

# Slurm job options (name, compute nodes, job time)
#SBATCH --nodes=8
#SBATCH --tasks-per-node=4
#SBATCH --job-name=hello
#SBATCH --time=00:01:00
#SBATCH --output=%x-%j.out
#SBATCH --cpus-per-task=1
#SBATCH --partition=standard
# Replace [budget code] below with your budget code (e.g. t01)
#SBATCH --account=ta035
# The commands below select the course-specific reservation
##SBATCH --qos=standard
##SBATCH --reservation=ta020_129

# The commands below select the short queue for small jobs
#SBATCH --qos=short
#SBATCH --reservation=shortqos

# The comamnds below select the standard queue
##SBATCH --qos=standard

module --silent load epcc-job-env

# Set the number of threads to 1
#   This prevents any threaded system libraries from automatically
#   using threading.

export OMP_NUM_THREADS=1

# Use "srun" to launch the job

srun --distribution=block:block --hint=nomultithread ./hello
```
### Notes
Here ta035 is the budget code

## Running a Batch job
You run a batch job in slurm using

```sbatch job1.job```
