#!/bin/sh
#
# $NetBSD: squid.sh,v 1.2 1998/05/24 19:59:28 tron Exp $
#
if [ -x @PREFIX@/sbin/RunCache -a -f @PREFIX@/etc/squid/squid.conf ];
then
 @PREFIX@/sbin/RunCache >/dev/null 2>&1 &
 echo -n ' squid'
fi
exit 0
