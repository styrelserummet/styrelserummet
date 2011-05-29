#!/bin/sh
set -x

test -e KEb90.gif || wget http://i.imgur.com/KEb90.gif

#for i in `seq -f "%02g" 0 15`
#do
#echo $i
#convert KEb90.gif[$i] image$i.bmp
#done
#
#montage image*.bmp montage.bmp

#montage KEb90.gif[0-15] -geometry 16x16+1+1  tile_0.bmp

#montage KEb90.gif[1-14] -tile 1x14 tile_0.bmp
montage KEb90.gif[1-14] -background black tile_0.bmp
