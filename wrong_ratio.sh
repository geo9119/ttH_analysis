#!/bin/bash
 
for i in {1..234..1}
        do
	root -l .x masses_wrong_ratio_opt.C'("/home/george/Desktop/wrong_weights/output/benchmark_ttH_'$i'.dat.out")' <<-EOF 
	.q
	EOF
	mv wrng_sol_half1.root wrng_sol_half1_$i.root	
	mv crrct_sol.root crrct_sol_$i.root
	mv wrng_sol_half2.root wrng_sol_half2_$i.root
done
