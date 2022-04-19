# level14

We cannot discover anything for the level14, the only thing we can now exploit is `getflag` binary.

We will attempt to spoof our uid like before.

```bash
level14@SnowCrash:/tmp$ id flag14
uid=3014(flag14) gid=3014(flag14) groups=3014(flag14),1001(flag)
```

I was going to use `LD_PRELOAD` to inject an uid, detours ptrace, getenv... But there was too much protections after talking with some people, I decided I'll go with gdb only.

```bash
Injection Linked lib detected exit..
[...]
LD_PRELOAD detected through memory maps exit ..
```

So, after searching and playing with `LD_PRELOAD`, I've learnt that I will have to detourn `ptrace` first, then inject the uid.

Googling [gbd bypass ptrace](https://gist.github.com/poxyran/71a993d292eee10e95b4ff87066ea8f2).. Let's use the same pattern as the previous level to change the uid.

```bash
level14@SnowCrash:/tmp/ressources$ gdb /bin/getflag
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /bin/getflag...(no debugging symbols found)...done.
(gdb) catch syscall ptrace
Catchpoint 1 (syscall 'ptrace' [26])
(gdb) commands 1
Type commands for breakpoint(s) 1, one per line.
End with a line saying just "end".
>set ($eax) = 0
>continue
>end
(gdb) b getuid
Breakpoint 2 at 0x80484b0
(gdb) run
Starting program: /bin/getflag 

Catchpoint 1 (call to syscall ptrace), 0xb7fdd428 in __kernel_vsyscall ()

Catchpoint 1 (returned from syscall ptrace), 0xb7fdd428 in __kernel_vsyscall ()

Breakpoint 2, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
(gdb) step
Single stepping until exit from function getuid,
which has no line number information.
0x08048b02 in main ()
(gdb) print $eax
$1 = 2014
(gdb) set $eax=3014
(gdb) step
Single stepping until exit from function main,
which has no line number information.
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```

Cool, let's get our last flag.

```bash
level14@SnowCrash:/tmp/ressources$ su flag14
Password: 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
Congratulation. Type getflag to get the key and send it to me the owner of this livecd :)
flag14@SnowCrash:~$ 
```
