# level00

Intra video gave an hint on how to start.
We are going to check which files level00 owns.

```bash
level00@SnowCrash:~$ find / -user flag00 2>/dev/null
/usr/sbin/john
/rofs/usr/sbin/john
```

If we read content of a file, we get the following output.

```bash
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
level00@SnowCrash:~$ cat /rofs/usr/sbin/john
cdiiddwpgswtgt
```

Alright, we can try as flag. It dosen't work.
Let's try video ressource [dcode](https://www.dcode.fr/caesar-cipher).

First who is english valid is `nottoohardhere`.

```bash
level00@SnowCrash:~$ su flag00
Password: nottoohardhere
Don't forget to launch getflag !
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
```

Cool ! We can go to level01.

```bash
flag00@SnowCrash:~$ su level01
Password: x24ti5gi3x0ol2eh4esiuxias
level01@SnowCrash:~$ 
```
