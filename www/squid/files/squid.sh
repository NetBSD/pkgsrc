#!/bin/sh
#
# $NetBSD: squid.sh,v 1.1 1998/05/23 21:27:21 tron Exp $
#
if [ -x @PREFIX@/sbin/RunCache -a -f @PREFIX@/etc/squid/squid.conf ];
then
 (cd /var/run; @PREFIX@/sbin/RunCache >/dev/null 2>&1 &)
 echo -n ' squid'
fi
exit 0
