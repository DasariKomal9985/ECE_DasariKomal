
#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");

    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] != '.')
        {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);

    return 0;
}




/*


2. Compile and run ⚙️
gcc mini_ls.c -o mini_ls
./mini_ls


Example output:

file_logger.c
mycat.c
mycp.c
mini_ls.c
source.txt


Your output will depend on the files in your current directory.

3. Functions used
Function	Purpose
opendir()	Opens a directory
readdir()	Reads directory entries one by one
closedir()	Closes the directory
printf()	Displays filenames

Note: "." means the current directory. This program hides names beginning with . (hidden files), similar to the default ls behavior.

One-line definition: A mini ls command is a C program that lists filenames in a directory using directory-handling functions. 🚀



*/
