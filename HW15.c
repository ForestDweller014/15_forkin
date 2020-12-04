#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int main() {
	int f1, f2, status, t_sleep;
	printf("Before forking...\n");
	f1 = fork();
	if (f1) {
		f2 = fork();
	}
	if (!f1 || !f2) {
		printf("Child process ID: %d\n", getpid());
		srand(time(NULL));
		t_sleep = (int)((double)rand() / ((double)RAND_MAX + 1) * 9) + 2;
		sleep(t_sleep);
		printf("Child finished\n");
	} else {
		pid_t pid = wait(&status);
		printf("Child finished. Process ID: %d, Time asleep: %d\n", pid, WEXITSTATUS(status));
		printf("Parent finished\n");
	}
	return t_sleep;
}