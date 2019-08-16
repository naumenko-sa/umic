# summary_table

- Reads the input stream (single ended fastq) and reports the most frequent DNA fragments.
- usable for QC of barcodes (sample barcodes, cellular barcode) in scRNA-seq
- compiled with gcc >= 4.8.5
- test usage: 
```
gunzip -c data/test.R3.fq.gz | summary_table > data/test.R3.table.csv 2> messages.txt
head data/file.R3.table.csv
cat messages.txt
```
- real usage: 
```
gunzip -c real_huge.R3.fq.gz | head -n 40000000 | summary_table > real_huge.R3.table.csv 2> messages.txt
cat messages.txt
head real_huge.R3.table.csv
```
- O2 usage:
```
sbatch summary_table.sh real_huge.R3.fq.gz
```
- compilation: `compile.sh summary_table.cpp`. Result is summary_table binary.

