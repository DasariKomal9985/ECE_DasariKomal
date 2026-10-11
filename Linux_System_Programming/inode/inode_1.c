#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat info;

    if (stat("test.txt", &info) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("Inode number: %lu\n",
           (unsigned long)info.st_ino);

    printf("File size: %lld bytes\n",
           (long long)info.st_size);

    return 0;
}






/*

🔹 Inode in Linux 📂
An inode (index node) is a data structure in a Linux filesystem that stores information about a file, except its filename and the file's actual contents.
💻 Example in C
We can use stat() to get a file's inode number.



🔍 Explanation
Information			Meaning
st_ino			Inode number
st_size			File size in bytes
st_mode			File type and permissions
st_uid			Owner's user ID
st_gid			Owner's group ID
st_mtime		Last modification time




⚙️ How does an inode work?
Suppose you have a file named test.txt.
Filename: test.txt

Inode number: 12345
Metadata and references to file data

File data
The actual contents: Hello Linux



The inode stores metadata and information needed to locate the file's data. The filesystem directory maps the filename to the inode number.


📌 Useful Linux commands
ls -i test.txt


Displays the inode number.
stat test.txt


Displays detailed file information, including its inode number.

🔹 Inode vs File Descriptor
Inode										File descriptor
Identifies a filesystem object through its inode number.	Identifies an open resource within a process.
Stores file metadata.						Used with read(), write(), and close().
Obtained from filesystem metadata.				Commonly returned by open().


One-line definition: An inode is a filesystem data structure that stores a file's metadata and information for locating its contents. 😊



*/
