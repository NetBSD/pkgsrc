#!/bin/sh
#
# $NetBSD: navigator.sh,v 1.1.1.1 1999/02/22 07:45:22 abs Exp $
#
MOZILLA_HOME=@@MOZILLA_HOME@@ ;	export MOZILLA_HOME
XNLSPATH=$MOZILLA_HOME/nls ;		export XNLSPATH
XKEYSYMDB=$MOZILLA_HOME/XKeysymDB ;	export XKEYSYMDB
exec $MOZILLA_HOME/netscape ${1+$@}      
