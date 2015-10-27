#!/bin/bash
#
# encode.sh -- encoding glc stream to x264-encoded video
# Copyright (C) 2007-2008 Pyry Haulos
# For conditions of distribution and use, see copyright notice in glc.h

glc-play *.glc -y 1 -o - | ffmpeg -i - -c:v libx264 -preset veryslow -qp 0 output.avi

