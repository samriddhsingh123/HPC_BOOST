#!/bin/bash

# Define the list of programs
programs=("./fib" "./merge_sort" "./matrix_mult")

# Iterate over each program
for program in "${programs[@]}"; do
    # Run run_likwid.sh 4 times with different values of mal1_core for the current program
    for ((core = 0; core <= 3; core++)); do
        echo "Running $program with mal1_core = $core"
        /home/hpc/HPC_BOOST/test/run_likwid.sh "$program" "$core"
        sleep 1  # Optional: Add a delay between runs if needed
    done
done
