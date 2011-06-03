#!/bin/sh
set -x

#test -e BoatMan-MS4.gif || wget http://www.randomhoohaas.flyingomelette.com/Sprites/BoatMan-MS4.gif
#convert BoatMan-MS4.gif boatman.bmp
#convert -crop 30x50+2+0     boatman.bmp boatman_0.bmp
#convert -crop 30x50+33+0    boatman.bmp boatman_1.bmp
#convert -crop 30x50+62+0    boatman.bmp boatman_2.bmp
#convert -crop 30x50+90+0    boatman.bmp boatman_3.bmp
#convert -crop 30x50+118+0   boatman.bmp boatman_4.bmp
#convert -crop 30x50+148+0   boatman.bmp boatman_5.bmp
#
#montage boatman_[0-5].bmp -tile 6x1 -geometry +0+0 boatman_run.bmp

test -e boatman_run.bmp || wget http://www.zworqy.com/belma/bmp/boatman_run.bmp -O boatman_run.bmp
