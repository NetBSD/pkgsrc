#!/bin/sh
#
# $NetBSD: apache.sh,v 1.3 2000/07/10 12:22:27 hubertf Exp $
#

CMD=${1:-start}

if [ -x @PREFIX@/sbin/httpd -a -f @PREFIX@/etc/httpd/httpd.conf ]
then
 @PREFIX@/sbin/apachectl $CMD >/dev/null
 echo -n ' apache'
fi
exit 0
