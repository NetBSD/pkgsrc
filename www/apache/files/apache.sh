#!/bin/sh
#
# $NetBSD: apache.sh,v 1.1 1999/05/11 18:32:24 tron Exp $
#
if [ -x @PREFIX@/sbin/httpd -a -f @PREFIX@/etc/httpd/httpd.conf ]
then
 @PREFIX@/sbin/apachectl start
 echo -n ' apache'
fi
exit 0
