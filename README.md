# 42Cursus project Level1 "get_next_line"

## *Description

     Write a function which returns a line read from a file descriptor, without the newline.

## *Available Functions

    read, malloc, free

## *Prototype

```c
int   get_next_line(int fd, char **line);
```

## *Return Value
|  Return Value  | |
|:----:|:----:|
| 1 | A line has been read |
| 0 | EOF has been reached |
|-1 | An error happened    |
