# level01

After trying to get informations on level01 user, without success, I decided to check /etc/passwd.

```bash
level01@SnowCrash:~$ cat /etc/passwd
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

Ok, trying flag, it dosen't work. Back to utilities list.

It's not a program but it feels like an encoded password again.

We used dcode already, let's try John The Ripper on my machine.

```bash
➜  level01 git:(main) ✗ chmod +x ./ressources/john.sh 
➜  level01 git:(main) ✗ ./ressources/john.sh

root@jtr:/jtr/run# ./john /ressources/level01.encoded
Using default input encoding: UTF-8
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 256/256 AVX2])
Will run 16 OpenMP threads
Proceeding with single, rules:Single
Press 'q' or Ctrl-C to abort, almost any other key for status
Almost done: Processing the remaining buffered candidate passwords, if any.
Proceeding with wordlist:./password.lst
abcdefg          (?)     
1g 0:00:00:00 DONE 2/3 (2022-04-18 15:51) 14.28g/s 1404Kp/s 1404Kc/s 1404KC/s 123456..Nelson8
Use the "--show" option to display all of the cracked passwords reliably
Session completed.
```

Cool ! Let's try `abcdefg`.

```bash
level01@SnowCrash:~$ su flag01
Password: abcdefg
Don't forget to launch getflag !
flag01@SnowCrash:~$ getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf
```

Let's go to level02.

```bash
flag01@SnowCrash:~$ su level02
Password: f2av5il02puano7naaf6adaaf
level02@SnowCrash:~$ 
```
