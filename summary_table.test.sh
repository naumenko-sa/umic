#!/bin/bash
gunzip -c data/test.R3.fq.gz | summary_table > data/test.R3.table.csv 2> data/summary_table.messages.txt
cat data/summary_table.messages.txt
head data/test.R3.table.csv
