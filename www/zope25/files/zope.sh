#!/bin/sh
# $NetBSD: zope.sh,v 1.1.1.1 2002/08/22 16:54:49 drochner Exp $

case $1 in
start)
	INSTANCE_HOME=@INSTANCEHOME@
	export INSTANCE_HOME
	(cd @INSTANCEHOME@ && @PYTHONBIN@ @ZOPEDIR@/z2.py)
	;;
stop)
	kill `cat @INSTANCEHOME@/var/Z2.pid`
	;;
esac
