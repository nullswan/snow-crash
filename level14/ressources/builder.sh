gcc -shared -fPIC -o getuid.so getuid.c
gcc -shared -fPIC -o ptrace.so ptrace.c
gcc -shared -fPIC -o getenv.so getenv.c -ldl

# export LD_PRELOAD=/tmp/ressources/getuid.so:/tmp/ressources/ptrace.so:/tmp/ressources/getenv.so