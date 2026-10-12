
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
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}






/*


📂 readdir() in Linux System Programming

1. What is readdir()?
readdir() is a POSIX library function used to read directory entries one by one, such as filenames and subdirectory names.
It is commonly used with opendir() to implement commands like ls.




2. Syntax
struct dirent *readdir(DIR *dirp);


- dirp — pointer returned by opendir().
- struct dirent * — pointer to the directory entry.
- d_name — contains the entry's filename.



4. Compile and run ⚙️
Save the program as readdir.c.
gcc readdir.c -o readdir
./readdir


Example output:
.
..
file_logger.c
mini_ls.c
opendir.c
readdir.c


The output depends on the contents of your current directory. Unlike our mini ls example, this program also displays . and ...



5. Return value
- Success: Returns a pointer to a struct dirent containing the next entry.
- End of directory: Returns NULL.
- Error: Also returns NULL; check errno to distinguish an error from the end of the directory.


6. Important structure member
Member	Meaning
entry->d_name	Filename or directory name
entry->d_ino	Inode number
entry->d_type	Entry type, when supported by the filesystem


One-line definition: readdir() reads the next entry from an opened directory stream. 📁


*/
