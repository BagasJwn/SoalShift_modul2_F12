#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}


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

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
  DIR *d;
  struct dirent *dir;
  d = opendir("/home/jendralhoki/modul2/");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
	if (strcmp (get_filename_ext(dir->d_name),"png") == 0)
{
	char temp[100]="";
	strncpy (temp, dir->d_name, (strlen(dir->d_name)-4));
	strcat(temp, "_grey.png");
	char old[100]="";
	strcpy(old, "/home/jendralhoki/modul2/");
	strcat(old, dir->d_name);
	char baru[100]="";
	strcpy(baru, "/home/jendralhoki/modul2/gambar/");
	strcat(baru, temp); 
	rename (old, baru);
	}
    }
}
    closedir(d);
    sleep(10);
  }
  exit(EXIT_SUCCESS);
}

