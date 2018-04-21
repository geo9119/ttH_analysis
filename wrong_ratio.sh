#!/bin/bash
 
for i in {1..184..1}
        do
	root -l .x masses_wrong_ratio_opt.C'("/home/george/Desktop/ttjets_new/output/ttjets_'$i'.txt.out")' <<-EOF 
	.q
	EOF
	mv ttjets.root ttjets_$i.root	

done
