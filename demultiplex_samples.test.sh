#!/bin/bash
mkdir demultiplexed -p
gunzip -c test/umitransformed.fq.gz | demultiplex_samples test/barcodes.csv demultiplexed
