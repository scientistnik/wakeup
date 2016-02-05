#!/bin/sh

# $1 - time wakeup
# $2 - message need show

time_now=`date '+%T'`

time_need=$(date --date=$1 +"%H%M%S")
time_here=$(date +"%H%M%S")

if [ $time_need -ge $time_here ]
then
	while [ $time_now != $1 ]
	do
		sleep 1s
		time_now=`date '+%T'`
	done

	full_screen_message $2
fi

