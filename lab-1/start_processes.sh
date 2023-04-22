process_1 = "./test"
process_2 = "./test"

echo("Starting processes: ", process_1, " and ", process_2)
[status, cmdout] = system([process_1, " & ", process_2, " & "]);
# get the process IDs
[status, cmdout] = system("ps -ef | grep test | grep -v grep | awk '{print $2}'");
echo("Process IDs: ", cmdout)
# kill the processes
[status, cmdout] = system(["kill -9 ", cmdout]);