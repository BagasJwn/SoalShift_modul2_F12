#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
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
if (exists("/home/jendralhoki/sisop2019/modul2/shift/2/hatiku/elen.ku")){
char mode[] = "0777";
    char buf[100] = "/home/jendralhoki/sisop2019/modul2/shift/2/hatiku/elen.ku";
    int i;
    i = strtol(mode, 0, 8);
    chmod (buf,i);
struct stat info;
stat("/home/jendralhoki/sisop2019/modul2/shift/2/hatiku/elen.ku", &info); 
struct passwd *pw = getpwuid(info.st_uid);
struct group  *gr = getgrgid(info.st_gid);
if (strcmp (pw->pw_name, "www-data") == 0 && strcmp (gr->gr_name, "www-data") == 0 ){
remove ("/home/jendralhoki/sisop2019/modul2/shift/2/hatiku/elen.ku");
}




}
    sleep(3);
  }
  
  exit(EXIT_SUCCESS);
}
