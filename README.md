ls
==

An `ls` clone written in C that lists all files in a directory including their permissions, file size, owner group and last modified date.

Version
-------

Version 0.03

Synopsis
--------

    $ ls
    drwxrwxr-x   4 sillymoose sillymoose 1 Sep  9 23:41 .
    drwxrwxr-x   4 sillymoose sillymoose 1 Sep  9 23:41 ..
    drwxrwxr-x   7 sillymoose sillymoose 1 Sep  9 23:30 .git
    -rw-rw-r--   1 sillymoose sillymoose 1 Sep  9 23:30 LICENSE
    -rwxrwxr-x   1 sillymoose sillymoose 1 Sep  9 23:41 ls
    drwxrwxr-x   2 sillymoose sillymoose 1 Sep  9 23:42 src

    $ ls LICENSE
    -rw-rw-r--   1 sillymoose sillymoose 1 Sep  9 23:30 LICENSE

    $ ls src
    drwxrwxr-x 2 sillymoose sillymoose 1 Sep 11 22:59 .
    drwxrwxr-x 5 sillymoose sillymoose 1 Sep 11 22:59 ..
    -rw-rw-r-- 1 sillymoose sillymoose 1 Sep 11 22:59 ls.c

To Do
-----

 * Sort output alpabetically by filename
 * Display filename only (not file path)
 * Fix width of file size column
