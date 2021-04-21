#!/bin/bash

#backlight
backLight=$(xbacklight |cut -d. -f1)

#battery
Battery=$(cat /sys/class/power_supply/BAT0/capacity)%
Batterystatus=$(cat /sys/class/power_supply/BAT0/status)
if [[ $Batterystatus == D* ]];then 
       Batterystatus='🔋 ';
else Batterystatus='🔌 ';
fi

#volumee
Volume =$(amixer get Master |tail -n1 |cut -d'[' -f2 |cut -d']' -f1)
if [[$Volume == off ]];then
	Volume='mute'
else
	Volume=$(amixer get Master |tail -n1 |cut -d'[' -f2 |cut -d']' -f1)
fi

#datetime

#DateTime=$(date +"%a %m-%d %T")
DateTime=$(date +"%a %T")
#memfree=$(($(grep -m1 'MemAvailable:' /proc/meminfo | awk '{print $2}') / 1024))
#memtotal=$(($(grep -m1 'MemTotal:' /proc/meminfo | awk '{print $2}') / 1024))
memuse=$(($(free |grep Mem|awk '{print $3}') /1024))
memtotal=$(($(free |grep Mem|awk '{print $2}') /1024))
#memuse=$(($memtotal - $memfree))

xsetroot -name "|  $memuse M/$memtotal M | $Batterystatus $Battery | ☀ $backLight % | 🔊 $Volume | 📆 $DateTime"
