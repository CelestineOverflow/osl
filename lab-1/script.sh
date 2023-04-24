# Compile the C program
gcc -o counter counter.c

# Declare an array of niceness values
niceness_values=(-20 -15 -10 -5 0 5 10 15 20 20)

# Spawn 10 instances of the program with different niceness values
for i in "${!niceness_values[@]}"; do
    nice -n "${niceness_values[$i]}" ./counter "${niceness_values[$i]}"&
done

# Wait for all instances to finish
wait

echo "All instances have finished."
