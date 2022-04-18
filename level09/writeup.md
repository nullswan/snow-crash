# level09

Using `ls`, we can discover another couple of files.

```bash
level09@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09 level09   26 Mar  5  2016 token
```

Our token file is readable but feels a bit encrypted as the flag obtained does not work.

```bash
level09@SnowCrash:~$ cat token
f4kmm6p|=�p�n��DB�Du{��
level09@SnowCrash:~$ ./level09 token
tpmhr
```

After trying to get information on the binary we can see the following pattern.

```bash
level09@SnowCrash:~$ ./level09 aab
abd
level09@SnowCrash:~$ ./level09 01234
02468
level09@SnowCrash:~$ ./level09 00000
01234
```

Ok, it appear the binary take the letter and add his index.

Let's get hex content of token file as we have non-printable characters. We will skip 0a (`\n`).

```bash
level09@SnowCrash:~$ hexdump -C token
00000000  66 34 6b 6d 6d 36 70 7c  3d 82 7f 70 82 6e 83 82  |f4kmm6p|=..p.n..|
00000010  44 42 83 44 75 7b 7f 8c  89 0a                    |DB.Du{....|
0000001a
```

I created a python script that does the index calculation.

```bash
➜  level09 git:(main) ✗ python3 ressources/decode.py 
f3iji1ju5yuevaus41q1afiuq
```

Let's get a flag.

```bash
level09@SnowCrash:~$ su flag09
Password: f3iji1ju5yuevaus41q1afiuq
Don't forget to launch getflag !
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```

And head to level10.

```bash
flag09@SnowCrash:~$ su level10
Password: s5cAJpM8ev6XHw998pRWG728z
level10@SnowCrash:~$ 
```
