# get_next_line (school 21 project)

Simple analog of C funclion ``getline``

---
### Index

* [Description](#Description)
* [How_to_run](#How_to_run)
* [Contacts](#Contacts)

### Description

This is the second project in the 42 Cadet Curriculum. The aim of this project is to write a function that returns a line, read from a file, using only ``read``, ``malloc`` and ``free`` functions. In addition, program should provide the ability to set the buffer size for reading. here you can get some information about [standart getline](https://man7.org/linux/man-pages/man3/getline.3.html)

Bonus version of the program also can work with several file descriptors at once.

### How_to_run

In case to just test the code, you need to write some ``main`` function and compile code that way:

**Usual version:** ``gcc -D BUFFER_SIZE=xx your_file_with_main.c get_next_line.c get_next_line_utils_bonus.c``  
**Bonus version:** ``gcc -D BUFFER_SIZE=xx your_file_with_main.c get_next_line_bonus.c get_next_line_utils.c``

And then run: ``./a.out`` file. You can set appropriate buffer size by changing the value of ``xx`` it the script.  Or you coud apply this code to some other projects by just adding files into them: ``get_next_line.c get_next_line_utils_bonus.c get_next_line.h`` to use usual version or ``get_next_line_bonus.c get_next_line_utils.c get_next_line_bonus.h`` to use bonus version.

### Contacts
Feel free to clone this project, check the code or contact me if you have any question or suggestions:

* 21 Login:   **gajayme**
* Email:    **DonBazilikos@gmail.com**

Good luck and ave a good time! 📒📒📒
