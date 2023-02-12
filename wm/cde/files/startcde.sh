#!/bin/sh

export PATH=$PATH:@PREFIX@/dt/bin
export MANPATH=$PATH:@PREFIX@/dt/man
export LANG=C

if test "x$DISPLAY" = "x"
then
  echo "$0: Starting X server"
  prog=xinit
else
  echo "$0: X server already running on display $DISPLAY"
  prog=ksh93
fi


exec $prog @PREFIX@/dt/bin/Xsession
