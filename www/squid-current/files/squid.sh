#!/bin/sh
#
# $NetBSD: squid.sh,v 1.1.1.1 1998/10/09 17:49:20 kim Exp $
#
if [ -x @PREFIX@/sbin/RunCache -a -f /etc/squid.conf ];
then
 @PREFIX@/sbin/RunCache >/dev/null 2>&1 &
 echo -n ' squid'
fi
exit 0
