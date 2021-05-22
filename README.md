# 42Cursus project Level1 "get_next_line"

## *Description

     This is a function which returns a line read from a file descriptor, without the newline.
     This program must compile with the flag -D BUFFER_SIZE=xx. which will be used as the buffer size for the read calls in my get_next_line. 

## *Available Functions

    read, malloc, free

## *Prototype

```c
int   get_next_line(int fd, char **line);
```

## *Parameters

|  Return Value  | |
|:----:|:----:|
| #1 |  file descriptor for reading |
| #2 | The value of what has been read |

## *Return Value
|  Return Value  | |
|:----:|:----:|
| 1 | A line has been read |
| 0 | EOF has been reached |
|-1 | An error happened    |
