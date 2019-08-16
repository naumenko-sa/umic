#!/bin/bash

#!/bin/bash

# https://slurm.schedmd.com/sbatch.html

#SBATCH --partition=priority        # Partition (queue)
#SBATCH --time=5:00:00              # Runtime in D-HH:MM format
#SBATCH --job-name=ressler            # Job name
#SBATCH -c 16
#SBATCH --mem=20G            # Memory needed per CPU
#SBATCH --output=project_%j.out     # File to which STDOUT will be written, including job ID
#SBATCH --error=project_%j.err      # File to which STDERR will be written, including job ID
#SBATCH --mail-type=ALL             # Type of email notification (BEGIN, END, FAIL, ALL)

bname=`basename $1 .fq`

export LC_ALL=aa_DJ.utf8 && export LANG=aa_DJ.utf8 && /n/app/bcbio/dev/anaconda/envs/python2/bin/python \
/n/app/bcbio/tools/bin/umis cb_filter --cores 16 \
--bc1 /n/app/bcbio/dev/anaconda/lib/python3.6/site-packages/bcbio/rnaseq/../data/umis/harvard-indrop-v3-cb1.txt.gz \
--nedit 1 \
--bc2 /n/app/bcbio/dev/anaconda/lib/python3.6/site-packages/bcbio/rnaseq/../data/umis/harvard-indrop-v3-cb2.txt.gz \
$1 \
| gzip > $bname.filtered.fq.gz
