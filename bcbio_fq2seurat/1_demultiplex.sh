#!/bin/bash

# https://slurm.schedmd.com/sbatch.html

#SBATCH --partition=priority        # Partition (queue)
#SBATCH --time=5-00:00:00              # Runtime in D-HH:MM format
#SBATCH --job-name=ressler            # Job name
#SBATCH -c 1
#SBATCH --mem=10G            # Memory needed per CPU
#SBATCH --output=project_%j.out     # File to which STDOUT will be written, including job ID
#SBATCH --error=project_%j.err      # File to which STDERR will be written, including job ID
#SBATCH --mail-type=ALL             # Type of email notification (BEGIN, END, FAIL, ALL)


export LC_ALL=aa_DJ.utf8 && export LANG=aa_DJ.utf8 &&  \
/n/app/bcbio/dev/anaconda/envs/python2/bin/python /n/app/bcbio/tools/bin/umis demultiplex_samples \
--nedit 1 \
--barcodes barcodes.csv \
--out_dir demultiplexed \
ressler.umitransformed.fq.gz
