#!/bin/sh

cat /etc/passwd| grep -v \# | sed -n 'n;p' | cut -d ':' -f1 | rev | sort -r | sed -n $(echo $FT_LINE1),$(echo $FT_LINE2)p | awk 1 ORS=', ' | sed 's/..$/./' | tr -d '\n'
