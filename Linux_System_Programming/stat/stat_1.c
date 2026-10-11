#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat file_info;

    if (stat("test.txt", &file_info) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("File size: %lld bytes\n",
           (long long)file_info.st_size);

    printf("File permissions: %o\n",
           (unsigned int)(file_info.st_mode & 0777));

    printf("Number of hard links: %lu\n",
           (unsigned long)file_info.st_nlink);

    printf("Last modified time: %lld\n",
           (long long)file_info.st_mtime);

    return 0;
}






/*

🔹 stat() System Call in Linux 📂
The stat() system call is used to get information about a file, such as its size, permissions, type, and last modification time.





🔍 Explanation
Code					Purpose
struct stat			Structure that stores file information
stat("test.txt", &file_info)	Retrieves information about the file
st_size				File size in bytes
st_mode				File type and permissions
st_nlink			Number of hard links
st_mtime			Time of last modification




📌 Return values
Return value	Meaning
0	Success
-1	Failure; errno indicates the error


echo "Hello Linux" > test.txt
gcc stat.c -o stat_demo
./stat_demo

One-line definition: stat() retrieves metadata about a file without opening it for reading or writing. 😊
*/
