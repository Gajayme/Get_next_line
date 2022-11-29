# get_next_line (school 21 project)

This repository contains second Simple analog of C funclion ``getline``
[description](https://man7.org/linux/man-pages/man3/getline.3.html)

This is the second project in the 42 Cadet Curriculum. The aim of this project is to write a function that returns a line, read from a file descriptor, using only ``read``, ``malloc`` and ``free`` functions. In addition, program should be able to work with several descriptors at once and provide the ability to set the buffer size for reading



gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out


