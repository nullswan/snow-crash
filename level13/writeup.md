# level13

Using `ls`, we discover a binary.

```bash
level13@SnowCrash:~$ ls -l
total 8
-rwsr-sr-x 1 flag13 level13 7303 Aug 30  2015 level13
```

Let's discover more about our binary.

```bash
level13@SnowCrash:~$ readelf -p .rodata ./level13

String dump of section '.rodata':
  [     8]  0123456
  [    10]  UID %d started us but we we expect %d^J
  [    37]  boe]!ai0FB@.:|L6l@A?>qJ}I
  [    51]  your token is %s^J

level13@SnowCrash:~$ ./level13 
UID 2013 started us but we we expect 4242
level13@SnowCrash:~$ nm -u level13
         w _Jv_RegisterClasses
         w __gmon_start__
         U __libc_start_main@@GLIBC_2.0
         U exit@@GLIBC_2.0
         U getuid@@GLIBC_2.0
         U printf@@GLIBC_2.0
         U strdup@@GLIBC_2.0
```

Alright, we will spoof our uid. There is multiple ways, LD_PRELOAD or gdb.

The easier way will be gdb.

```bash
level13@SnowCrash:~$ gdb ./level13
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /home/user/level13/level13...(no debugging symbols found)...done.
(gdb) breakpoint getuid
Undefined command: "breakpoint".  Try "help".
(gdb) break getuid
Breakpoint 1 at 0x8048380
(gdb) run
Starting program: /home/user/level13/level13 

Breakpoint 1, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
(gdb) step
Single stepping until exit from function getuid,
which has no line number information.
0x0804859a in main ()
(gdb) print $eax
$1 = 2013
(gdb) set $eax=4242
(gdb) step
Single stepping until exit from function main,
which has no line number information.
your token is 2A31L79asukciNyi8uppkEuSx
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```

Here we go, let's head to level 14.

```bash
level13@SnowCrash:~$ su level14
Password: 2A31L79asukciNyi8uppkEuSx
level14@SnowCrash:~$ 
```
