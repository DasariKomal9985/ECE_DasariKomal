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

    printf("File Permissions:\n");

    printf("Owner: ");
    printf("%c", (info.st_mode & S_IRUSR) ? 'r' : '-');
    printf("%c", (info.st_mode & S_IWUSR) ? 'w' : '-');
    printf("%c\n", (info.st_mode & S_IXUSR) ? 'x' : '-');

    printf("Group: ");
    printf("%c", (info.st_mode & S_IRGRP) ? 'r' : '-');
    printf("%c", (info.st_mode & S_IWGRP) ? 'w' : '-');
    printf("%c\n", (info.st_mode & S_IXGRP) ? 'x' : '-');

    printf("Others: ");
    printf("%c", (info.st_mode & S_IROTH) ? 'r' : '-');
    printf("%c", (info.st_mode & S_IWOTH) ? 'w' : '-');
    printf("%c\n", (info.st_mode & S_IXOTH) ? 'x' : '-');

    return 0;
}






/*


🔹 File Permissions in Linux 🔐

File permissions determine who can read, write, or execute a file in Linux.

1. Types of permissions

Permission	Symbol	Meaning
Read	r	Read or view file contents
Write	w	Modify file contents
Execute	x	Run a file as a program or script


2. Who gets permissions?

Linux divides users into three categories:

Category	Symbol	Meaning
Owner	u	User who owns the file
Group	g	Users in the file's group
Others	o	Everyone else



Example:
ls -l test.txt


Output:
-rw-r--r-- 1 user user 12 Oct 11 test.txt



The permissions rw-r--r-- mean:
- Owner: rw- → read and write.
- Group: r-- → read only.
- Others: r-- → read only.
The first - indicates this is a regular file.




3. Numeric permissions 🔢
Permission		Number
Read (r)		4
Write (w)		2
Execute (x)		1
No permission (-)	0


Add the numbers to combine permissions:

- 7 = 4 + 2 + 1 = rwx
- 6 = 4 + 2 = rw-
- 5 = 4 + 1 = r-x
- 4 = read only (r--)


For example, 755 means:

- Owner: 7 → rwx
- Group: 5 → r-x
- Others: 5 → r-x




4. Common commands 💻
Command				Purpose
ls -l			View file permissions
chmod 755 test.sh	Set permissions to rwxr-xr-x
chmod 644 test.txt	Set permissions to rw-r--r--
chmod u+x test.sh	Add execute permission for the owner
chmod g-w test.txt	Remove write permission for the group
chown user test.txt	Change the file owner (usually requires appropriate privileges)




5. Simple practical example
touch test.sh
chmod 755 test.sh
ls -l test.sh


Possible output:
-rwxr-xr-x 1 user user 0 Oct 11 test.sh


Now the owner can read, write, and execute the file, while group members and others can read and execute it, subject to other system restrictions.

One-line definition: File permissions control which users can read, modify, and execute files in Linux. 😊





*/
