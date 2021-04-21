#!/bin/bash

/bin/bash ~/.dwm/dwm-status.sh &
/bin/bash ~/.dwm/dwm-wallpaper.sh &
/bin/bash ~/.dwm/tap-to-click.sh &
/bin/bash ~/.dwm/inverse-scroll.sh &
/usr/bin/picom -b
/usr/bin/fcitx5 &

/bin/bash ~/.dwm/temp.sh&
#/bin/xflux -l 41.8 -g 123.4 -k 3400 &
/bin/xflux -l 41.8 -g 143.4 -k 3400 &
/usr/bin/xmodmap $HOME/.Xmodmap &
/usr/bin/xcape -e 'Mode_switch=Escape' &


/usr/bin/wmname LG3D & #solve java app-swing don't display

