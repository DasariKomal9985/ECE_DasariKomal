Linux Commands Cheat Sheet 🐧
Here are useful Linux commands and keyboard shortcuts for copy, move, select all, save, exit, line numbers, editing files, and terminal operations.
1. Nano and Vim editor commands
These commands are used when editing files in the terminal.
A. Vim editor commands
Open a file:
vim main.c


Action	Command / Shortcut
Enter insert mode	i
Start inserting at line beginning	I
Add text after cursor	a
Save file	:w
Save and exit	:wq
Exit without saving changes	:q!
Exit if no unsaved changes	:q
Delete current line	dd
Copy (yank) current line	yy
Paste copied line below	p
Paste copied line above	P
Undo	u
Redo	Ctrl + r
Select entire file	ggVG
Show line numbers	:set number
Hide line numbers	:set nonumber
Go to first line	gg
Go to last line	G
Go to line 10	:10
Search text	/word
Find next match	n
Find previous match	N
Important: Press Esc before typing commands such as :wq, :q!, or :set number.
B. Nano editor commands
Open a file:
nano main.c


Action	Shortcut
Save file	Ctrl + O, then Enter
Exit	Ctrl + X
Cut current line	Ctrl + K
Paste cut/copied text	Ctrl + U
Search text	Ctrl + W
Go to a line number	Ctrl + _
Show cursor position	Ctrl + C
Select text (start selection)	Alt + A
Copy selected text	Alt + 6
Cut selected text	Ctrl + K
Undo	Alt + U
Redo	Alt + E
In Nano, ^ displayed at the bottom means Ctrl. For example, ^O means Ctrl + O.
2. Linux file and directory commands
Action	Command	Example
List files	ls	ls
List details	ls -l	ls -l
Show hidden files	ls -a	ls -a
Show current directory	pwd	pwd
Change directory	cd	cd Documents
Go to parent directory	cd ..	cd ..
Go to home directory	cd ~	cd ~
Create a directory	mkdir	mkdir project
Create an empty file	touch	touch main.c
Copy a file	cp	cp main.c backup.c
Copy a directory	cp -r	cp -r project backup
Move a file	mv	mv main.c Documents/
Rename a file	mv	mv old.c new.c
Delete a file	rm	rm main.c
Delete an empty directory	rmdir	rmdir project
Display file contents	cat	cat main.c
Display file page by page	less	less main.c
⚠️ Be careful with rm and rm -r: deleted files may not be recoverable easily.
3. Terminal copy, paste and select all
These are common shortcuts in Ubuntu's graphical terminal.
Action	Shortcut
Copy selected text	Ctrl + Shift + C
Paste text	Ctrl + Shift + V
Select all terminal text	Ctrl + Shift + A (in many GNOME Terminal versions)
Clear terminal display	Ctrl + L
Interrupt a running command	Ctrl + C
Suspend a running process	Ctrl + Z
Search terminal scrollback	Ctrl + Shift + F (supported terminals)
Close terminal tab	Ctrl + Shift + W
Open a new terminal tab	Ctrl + Shift + T
Note: Shortcuts vary by terminal application. Ctrl + C usually interrupts a running command; it is not the standard copy shortcut in Linux terminals.
4. Display line numbers in files
Using Vim
Show line numbers:
:set number


Hide line numbers:
:set nonumber


Show relative line numbers:
:set relativenumber


Using the cat command
Display a file with line numbers:
cat -n main.c


Number only non-empty lines:
cat -b main.c


Using nl
nl main.c


5. Useful terminal commands for C programming
Since you're practising C, these will be particularly useful.
Action	Command
Create a C file	touch main.c
Edit using Vim	vim main.c
Compile a C program	gcc main.c -o main
Run the program	./main
Compile with warnings	gcc -Wall -Wextra main.c -o main
Show compiler version	gcc --version
Find the GCC executable	which gcc
View previous commands	history
Repeat the last command	!!
Find a command's location	which vim
Check file type	file main.c
Check permissions	ls -l main.c
Change file permissions	chmod +x script.sh
Show running processes	ps aux
Monitor processes	top
6. Quick revision — most important commands
:wq

Save and exit Vim
Press Esc first.



dd

Delete a line in Vim
Deletes the current line.



yy

Copy a line in Vim
Yanks the current line.



ggVG

Select the entire file in Vim
Press Esc, then type ggVG.



cp

Copy files
Example: cp a.c b.c



mv

Move or rename files
Example: mv a.c b.c



Ctrl + C

Stop a running terminal command
Usually sends an interrupt signal.
