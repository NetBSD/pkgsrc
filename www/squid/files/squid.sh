#!/bin/sh
#
# $NetBSD: squid.sh,v 1.3 1998/12/06 12:42:00 tron Exp $
#
if [ -x @PREFIX@/sbin/RunCache -a -f /etc/squid.conf ];
then
 @PREFIX@/sbin/RunCache >/dev/null 2>&1 &
 echo -n ' squid'
fi
exit 0
