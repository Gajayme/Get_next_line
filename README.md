# get_next_line (school 21 project)

Simple analog of C funclion ``getline``

---
### Index

* [Description](#Description)
* [How_to_run](#How_to_run)
* 

### Description

This is the second project in the 42 Cadet Curriculum. The aim of this project is to write a function that returns a line, read from a file descriptor, using only ``read``, ``malloc`` and ``free`` functions. In addition, program should provide the ability to set the buffer size for reading. You can also read about [standart getline](https://man7.org/linux/man-pages/man3/getline.3.html)

Bonus version of the program also can work with several file descriptors at once.

### How_to_run

In case to just test the code, you need to write some ``main`` function and compile code that way:

**Usual version:** ``gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line_bonus.c get_next_line_utils.c``

**Bonus version:** ``gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils_bonus.c``

Or you coud apply this code in some other projects by just add files into them:

