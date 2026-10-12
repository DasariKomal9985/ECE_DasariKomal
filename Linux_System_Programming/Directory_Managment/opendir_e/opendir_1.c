
#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *dir;

    dir = opendir(".");

    if (dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("Directory opened successfully!\n");

    closedir(dir);

    return 0;
}



/*


📂 opendir() in Linux System Programming
1. What is opendir()?
opendir() is a POSIX library function used to open a directory so we can read its entries, such as filenames and subdirectory names.


2. Syntax
DIR *opendir(const char *name);


- name — directory path, such as "." or "/home/user".
- DIR * — pointer to the opened directory stream.



4. Compile and run ⚙️
gcc opendir.c -o opendir
./opendir



5. Return value
- Success: Returns a valid DIR * pointer.
- Failure: Returns NULL, for example, if the directory does not exist or permission is denied.


6. Common directory paths
Path	Meaning
"."	Current directory
".."	Parent directory
"/tmp"	The /tmp directory
"/home"	The /home directory

Important: opendir() opens the directory stream; it does not list filenames by itself. Use readdir() to read entries and closedir() when finished.


One-line definition: opendir() opens a directory stream for reading directory entries. 📁






*/
