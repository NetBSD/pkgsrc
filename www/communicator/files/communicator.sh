#!/bin/sh
#
# $NetBSD: communicator.sh,v 1.2 1999/06/18 23:14:17 abs Exp $
#
MOZILLA_HOME=@@MOZILLA_HOME@@ ;	export MOZILLA_HOME
XNLSPATH=$MOZILLA_HOME/nls ;		export XNLSPATH
XKEYSYMDB=$MOZILLA_HOME/XKeysymDB ;	export XKEYSYMDB
exec $MOZILLA_HOME/netscape "$@"
