#!/bin/sh
# $NetBSD: apache.sh,v 1.3 1998/09/17 12:21:56 frueauf Exp $

[ -x @@@PREFIX@@@/sbin/apachectl ] && @@@PREFIX@@@/sbin/apachectl start >/dev/null && echo -n ' apache'
