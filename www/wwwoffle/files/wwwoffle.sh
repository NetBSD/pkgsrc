#!/bin/sh
#
# $NetBSD: wwwoffle.sh,v 1.1 1998/06/06 17:03:58 tron Exp $
#
if [ -x @PREFIX@/sbin/wwwoffled -a -f @PREFIX@/etc/wwwoffle/wwwoffle.conf ];
then
 @PREFIX@/sbin/wwwoffled -c @PREFIX@/etc/wwwoffle/wwwoffle.conf >/dev/null 2>&1 &
 echo -n ' wwwoffled'
fi
exit 0
