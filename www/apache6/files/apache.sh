#!/bin/sh
#
# $NetBSD: apache.sh,v 1.3 2000/09/20 05:14:12 jlam Exp $
#
# PROVIDE: apache
# REQUIRE: DAEMON

CMD=${1:-start}

if [ -x @PREFIX@/sbin/httpd -a -f @PREFIX@/etc/httpd/httpd.conf ]
then
 @PREFIX@/sbin/apachectl $CMD >/dev/null
 echo -n ' apache'
fi
exit 0
