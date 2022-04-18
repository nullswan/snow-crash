# https://hub.docker.com/r/phocean/john_the_ripper_jumbo

docker run -it --hostname jtr --rm -v $(pwd)/ressources:/ressources:ro phocean/john_the_ripper_jumbo
