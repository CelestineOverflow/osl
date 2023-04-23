#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#define MAX_TIME 30

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./print_string <string>\n");
        return 1;
    }
    char *niceness = argv[1];
    long long counter = 0;
    time_t start_time, current_time;
    pid_t pid = getpid();

    // Get the start time
    time(&start_time);

    // Run for 60 seconds
    do {
        counter++;
        time(&current_time);
    } while (difftime(current_time, start_time) < MAX_TIME);

    // Generate the file name
    char file_name[50];
    snprintf(file_name, sizeof(file_name), "%d.txt", pid);

    // Write the counter value to the file
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error: Unable to open the file.\n");
        return 1;
    }

    fprintf(file, "counter = %lld\n", counter);
    fprintf(file, "niceness = %s\n", niceness);
    
    fclose(file);

    printf("Counter value is written to the file %s\n", file_name);

    return 0;
}
