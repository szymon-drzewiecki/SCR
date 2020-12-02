#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_S 50

int main(int argc, char *argv[]){
  int fd[2];
  pid_t cpid;
  char buf;
  
  if (argc != 2){
    printf("Niepoprawna liczba argumentow");}

  if (pipe(fd) == -1){
    printf("Blad podczas wywolywania potoku");}

  cpid = fork();

  if (cpid == 0){
    close(fd[1]);
    char read_line[BUFFER_S];
    while(read(fd[0], read_line, sizeof(read_line))){
      printf("# %s #", read_line);}
    close(fd[0]);
  }

  else {
    FILE *fptr;
    if ((fptr = fopen(argv[1], "r")) == NULL){
      printf("Bledna nazwa pliki");
      return 1;}

    char write_buffer[BUFFER_S];
    close(fd[0]);

    while(fgets(write_buffer, sizeof(write_buffer), fptr)){
      write(fd[1], write_buffer, strlen(write_buffer));
    }
    close(fd[1]);
    fclose(fptr);
  }

  return 0;
}
