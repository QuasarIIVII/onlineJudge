#include <iostream>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <chrono>

using namespace std;

int main() {
    // Command to execute
    const char* command = "./a";

    // Start time
    auto start_time = chrono::high_resolution_clock::now();
    
    // Resource usage before executing the command
    struct rusage usage_start;
    getrusage(RUSAGE_CHILDREN, &usage_start);

    // Fork the process to execute the command
    pid_t pid = fork();

    if (pid == 0) {
        // Child process: execute the command
        execlp(command, command, (char*)nullptr);
    } else {
        // Parent process: wait for the child to finish
        wait(NULL);

        // End time
        auto end_time = chrono::high_resolution_clock::now();

        // Resource usage after executing the command
        struct rusage usage_end;
        getrusage(RUSAGE_CHILDREN, &usage_end);

        // Calculate user CPU time in seconds and convert to milliseconds
        double user_time_sec = (usage_end.ru_utime.tv_sec - usage_start.ru_utime.tv_sec) +
                               (usage_end.ru_utime.tv_usec - usage_start.ru_utime.tv_usec) / 1e6;
        double user_time_ms = user_time_sec * 1000;

        // Calculate elapsed time in milliseconds
        chrono::duration<double, milli> elapsed_time = end_time - start_time;

        // Output the results
        cout << "User CPU time: " << user_time_ms << " ms" << endl;
        cout << "Elapsed time: " << elapsed_time.count() << " ms" << endl;
    }

    return 0;
}
