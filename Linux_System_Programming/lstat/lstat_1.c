#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat file_info;

    if (lstat("test.txt", &file_info) == -1)
    {
        perror("lstat");
        return 1;
    }

    printf("File size: %lld bytes\n",
           (long long)file_info.st_size);

    printf("File permissions: %o\n",
           (unsigned int)(file_info.st_mode & 0777));

    if (S_ISLNK(file_info.st_mode))
        printf("This is a symbolic link\n");
    else if (S_ISREG(file_info.st_mode))
        printf("This is a regular file\n");

    return 0;
}






/*



🔹 lstat() System Call in Linux 📂
The lstat() system call is used to get information about a file or symbolic link using its path.
The important difference is that if the path refers to a symbolic link, lstat() returns information about the link itself, not the file it points to.



🔍 Explanation
Code					Purpose
lstat()				Gets file metadata without opening the file
struct stat			Stores file information
st_size				File size in bytes
st_mode				File type and permissions
S_ISLNK()			Checks whether the path is a symbolic link
S_ISREG()			Checks whether it is a regular file





📌 Return values
Return value	Meaning
0	Success
-1	Failure; errno indicates the error


⚙️ Difference between stat(), fstat(), and lstat()

Call	Uses		If path is a symbolic link
stat()	Filename/path	Gets information about the target
fstat()	File descriptor	Gets information about the opened file
lstat()	Filename/path	Gets information about the link itself


One-line definition: lstat() retrieves metadata about a path and, unlike stat(), does not follow the final symbolic link. 😊



*/
