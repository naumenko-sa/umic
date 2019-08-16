#!/bin/bash

# https://slurm.schedmd.com/sbatch.html

#SBATCH --partition=priority       # Partition (queue)
#SBATCH --time=10:00:00            # Runtime in D-HH:MM format
#SBATCH --job-name=summary_table            # Job name
#SBATCH -c 1
#SBATCH --mem-per-cpu=1G            # Memory needed per CPU
#SBATCH --output=project_%j.out     # File to which STDOUT will be written, including job ID
#SBATCH --error=project_%j.err      # File to which STDERR will be written, including job ID
#SBATCH --mail-type=ALL             # Type of email notification (BEGIN, END, FAIL, ALL)


gunzip -c $1 | summary_table > $1.table.csv 
