// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/mman.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <fcntl.h>
// #include <pthread.h>

// #define SHM_NAME "/shm_example"
// #define MUTEX_NAME "/mutex_example"

// typedef struct {
//     pthread_mutex_t mutex;
//     int value;
// } shared_data;

// int main() {
//     int shm_fd;
//     shared_data *sh_data;

//     /* Create shared memory object and set its size */
//     shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
//     if (shm_fd == -1) {
//         perror("Shared memory");
//         return -1;
//     }

//     if (ftruncate(shm_fd, sizeof(shared_data)) != 0) {
//         perror("Shared memory size");
//         return -1;
//     }

//     /* Map shared memory object */
//     sh_data = (shared_data *)mmap(NULL, sizeof(shared_data), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
//     if (sh_data == MAP_FAILED) {
//         perror("Memory mapping");
//         return -1;
//     }

//     /* Initialize mutex */
//     pthread_mutexattr_t attrmutex;
//     pthread_mutexattr_init(&attrmutex);
//     pthread_mutexattr_setpshared(&attrmutex, PTHREAD_PROCESS_SHARED);
//     pthread_mutex_init(&sh_data->mutex, &attrmutex);

//     pid_t pid = fork();

//     if (pid < 0) {
//         perror("Fork");
//         return -1;
//     } else if (pid == 0) { /* Child process */
//         for (int i = 0; i < 10; ++i) {
//             pthread_mutex_lock(&sh_data->mutex);
//             if (sh_data->value != 0) {
//                 printf("Child read: %d\n", sh_data->value);
//                 sh_data->value = 0;
//             }
//             sh_data->value = i + 1;
//             printf("Child wrote: %d\n", sh_data->value);
//             pthread_mutex_unlock(&sh_data->mutex);
//             sleep(1);
//         }
//     } else { /* Parent process */
//         for (int i = 0; i < 10; ++i) {
//             pthread_mutex_lock(&sh_data->mutex);
//             if (sh_data->value != 0) {
//                 printf("Parent read: %d\n", sh_data->value);
//                 sh_data->value = 0;
//             }
//             sh_data->value = i + 1;
//             printf("Parent wrote: %d\n", sh_data->value);
//             pthread_mutex_unlock(&sh_data->mutex);
//             sleep(1);
//         }
//         wait(NULL);
//     }

//     /* Clean up */
//     munmap(sh_data, sizeof(shared_data));
//     shm_unlink(SHM_NAME);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/mman.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <fcntl.h>
// #include <pthread.h>

// #define SHM_NAME "/shm_example"
// #define MUTEX_NAME "/mutex_example"

// typedef struct {
//     pthread_mutex_t mutex;
//     size_t block_size;
//     char data[];
// } shared_data;

// int main() {
//     int shm_fd;
//     shared_data *sh_data;
//     size_t block_sizes[] = { 1024, 2048, 4096, 8192 , 16384, 32768, 65536, 131072, 262144, 524288 };
//     size_t num_sizes = sizeof(block_sizes) / sizeof(size_t);
//     char *temp_buf;
//     struct timespec start, end;
//     long long elapsed_ns;

//     for (size_t i = 0; i < num_sizes; ++i) {
//         size_t size = block_sizes[i];

//         /* Create shared memory object and set its size */
//         shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
//         if (shm_fd == -1) {
//             perror("Shared memory");
//             return -1;
//         }

//         if (ftruncate(shm_fd, sizeof(shared_data) + size) != 0) {
//             perror("Shared memory size");
//             return -1;
//         }

//         /* Map shared memory object */
//         sh_data = (shared_data *)mmap(NULL, sizeof(shared_data) + size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
//         if (sh_data == MAP_FAILED) {
//             perror("Memory mapping");
//             return -1;
//         }

//         /* Initialize mutex */
//         pthread_mutexattr_t attrmutex;
//         pthread_mutexattr_init(&attrmutex);
//         pthread_mutexattr_setpshared(&attrmutex, PTHREAD_PROCESS_SHARED);
//         pthread_mutex_init(&sh_data->mutex, &attrmutex);

//         /* Allocate temp buffer */
//         temp_buf = malloc(size);
//         memset(temp_buf, 0, size);

//         pid_t pid = fork();

//         if (pid < 0) {
//             perror("Fork");
//             return -1;
//         } else if (pid == 0) { /* Child process */
//             clock_gettime(CLOCK_REALTIME, &start);
//             //enter critical section
//             pthread_mutex_lock(&sh_data->mutex);
//             memcpy(sh_data->data, temp_buf, size);
//             pthread_mutex_unlock(&sh_data->mutex);
//             //exit critical section
//             clock_gettime(CLOCK_REALTIME, &end);
//             elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
//             printf("Child wrote %zu bytes in %lld ns\n", size, elapsed_ns);
//             exit(0);
//         } else { /* Parent process */
//             wait(NULL); /* Wait for child to finish writing */
//             clock_gettime(CLOCK_REALTIME, &start);
//             pthread_mutex_lock(&sh_data->mutex);
//             memcpy(temp_buf, sh_data->data, size);
//             pthread_mutex_unlock(&sh_data->mutex);
//             clock_gettime(CLOCK_REALTIME, &end);
//             elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
//             printf("Parent read %zu bytes in %lld ns\n", size, elapsed_ns);
//         }

//         /* Clean up */
//         munmap(sh_data, sizeof(shared_data) + size);

//         if (shm_unlink(SHM_NAME) != 0) {
//             perror("Unlink shared memory");
//             return -1;
//         }

//         free(temp_buf);
//     }


//     return 0;   
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <pthread.h>

// Define shared memory and mutex names
#define SHARED_MEMORY_NAME "/shm_example"
#define MUTEX_NAME "/mutex_example"

// Struct for shared data
typedef struct {
    pthread_mutex_t shared_mutex; // Mutex for synchronizing access
    size_t data_block_size;       // Size of the data block
    char data[];                  // Flexible array member for data
} shared_memory_data;

int main() {
    int shared_memory_fd;         // File descriptor for shared memory
    shared_memory_data *shm_data; // Pointer to shared memory data
    size_t block_sizes[] = { 1024, 2048, 4096, 8192 , 16384, 32768, 65536, 131072, 262144, 524288 }; // Sizes of data blocks
    size_t num_sizes = sizeof(block_sizes) / sizeof(size_t); // Number of sizes
    char *buffer;                 // Temporary buffer
    struct timespec start, end;   // Start and end times
    long long elapsed_ns;         // Elapsed time in nanoseconds

    // Iterate over each size
    for (size_t i = 0; i < num_sizes; ++i) {
        size_t size = block_sizes[i];

        /* Create shared memory object and set its size */
        shared_memory_fd = shm_open(SHARED_MEMORY_NAME, O_CREAT | O_RDWR, 0666);
        if (shared_memory_fd == -1) {
            perror("Shared memory");
            return -1;
        }

        if (ftruncate(shared_memory_fd, sizeof(shared_memory_data) + size) != 0) {
            perror("Shared memory size");
            return -1;
        }

        /* Map shared memory object */
        shm_data = (shared_memory_data *)mmap(NULL, sizeof(shared_memory_data) + size, PROT_READ | PROT_WRITE, MAP_SHARED, shared_memory_fd, 0);
        if (shm_data == MAP_FAILED) {
            perror("Memory mapping");
            return -1;
        }

        /* Initialize mutex for shared memory */
        pthread_mutexattr_t mutex_attributes;
        pthread_mutexattr_init(&mutex_attributes);
        pthread_mutexattr_setpshared(&mutex_attributes, PTHREAD_PROCESS_SHARED);
        pthread_mutex_init(&shm_data->shared_mutex, &mutex_attributes);

        /* Allocate temp buffer */
        buffer = malloc(size);
        memset(buffer, 0, size);

        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork");
            return -1;
        } else if (pid == 0) { /* Child process */
            clock_gettime(CLOCK_REALTIME, &start);
            //enter critical section
            pthread_mutex_lock(&shm_data->shared_mutex);
            memcpy(shm_data->data, buffer, size);
            pthread_mutex_unlock(&shm_data->shared_mutex);
            //exit critical section
            clock_gettime(CLOCK_REALTIME, &end);
            elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
            printf("Child wrote %zu bytes in %lld ns\n", size, elapsed_ns);
            exit(0);
        } else { /* Parent process */
            wait(NULL); /* Wait for child to finish writing */
            clock_gettime(CLOCK_REALTIME, &start);
            pthread_mutex_lock(&shm_data->shared_mutex);
            memcpy(buffer, shm_data->data, size);
            pthread_mutex_unlock(&shm_data->shared_mutex);
            clock_gettime(CLOCK_REALTIME, &end);
            elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
            printf("Parent read %zu bytes in %lld ns\n", size, elapsed_ns);
        }

        /* Clean up */
        munmap(shm_data, sizeof(shared_memory_data) + size);

        if (shm_unlink(SHARED_MEMORY_NAME) != 0) {
            perror("Unlink shared memory");
            return -1;
        }

        free(buffer);
    }

    return 0;   
}




       
