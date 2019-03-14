#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir(".")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
    struct stat filestat;

    stat("makan_enak.txt",&filestat);
            ctime(&filestat.st_atime);
	char makan[100];
	FILE *baru;
	while (filestat.st_atime + 30 > time(NULL)){
	int counter = 2,i;
	for (i = 1; i < 100; i++){
	sprintf(makan, "makan_sehat%d.txt", i);
	baru = fopen (makan, "r");
	if(baru==NULL)break;
	}
	baru = fopen (makan, "w");
	fclose(baru);
	counter++;
    sleep(5);

}
	}
  
  exit(EXIT_SUCCESS);
}
