#!/bin/sh
#
# $NetBSD: apache.sh,v 1.2 1999/05/11 18:38:31 tron Exp $
#
if [ -x @PREFIX@/sbin/httpd -a -f @PREFIX@/etc/httpd/httpd.conf ]
then
 @PREFIX@/sbin/apachectl start >/dev/null
 echo -n ' apache'
fi
exit 0
