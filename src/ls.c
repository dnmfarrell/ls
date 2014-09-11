#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/utsname.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdint.h>

void print_file_details (struct stat fd, char filename[])
{
    // is dir
    printf( (S_ISDIR(fd.st_mode)) ? "d" : "-");

    // perms
    printf( (fd.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fd.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fd.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fd.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fd.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fd.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fd.st_mode & S_IROTH) ? "r" : "-");
    printf( (fd.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fd.st_mode & S_IXOTH) ? "x " : "- ");

    //size
    printf("%jd ", (intmax_t)fd.st_size);

    // owner, group name
    struct passwd *pw = getpwuid(fd.st_uid);
    struct group  *gr = getgrgid(fd.st_gid);
    printf("%10s ", (pw != 0) ? pw->pw_name : "unknown" );
    printf("%10s ", (gr != 0) ? gr->gr_name : "unknown" );

    // last modified
    char buff[16];
    strftime(buff, 20, "%Y-%m-%d %H:%M", localtime(&fd.st_mtime));
    printf("%16s ", buff);

    // filename
    printf("%-40s\n", filename);
}

void print_dir_details(char dir[])
{
   struct dirent *pDirent;
    DIR *pDir;
   pDir = opendir (dir);

   if (pDir != NULL)
   {
      while ((pDirent = readdir(pDir)) != NULL)
      {
         struct stat file_stats;
         if(stat(pDirent->d_name,&file_stats) < 0)
         {
            break;
         }
         print_file_details(file_stats, pDirent->d_name);
      }
   }
    closedir (pDir);
}

int main(int argc, char *argv[]) {

    char cwd[1024];

    if (argc < 2) {
        // use current working directory
        getcwd(cwd, sizeof(cwd));
    }
    else {
      int len = strlen(argv[1]);
        strncpy(cwd, argv[1], len);
      cwd[len] = '\0';
    }

    struct stat file_stats;
    if(stat(cwd,&file_stats) < 0)
   {
      puts("File not found");
        return 1;
   }

   // it's a directory so open it
   if (S_ISDIR(file_stats.st_mode))
   {
      print_dir_details(cwd);
   }
   else {
      print_file_details(file_stats, cwd);
   }

    return 0;
}

