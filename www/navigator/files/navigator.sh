#!/bin/sh
#
# $NetBSD: navigator.sh,v 1.4 2000/10/28 13:03:02 tron Exp $
#

# Avoid multi user problems caused by debug code in 4.76
rm -f /tmp/ndebug 2>/dev/null
ln -s /dev/null /tmp/ndebug 2>/dev/null

MOZILLA_HOME=@@MOZILLA_HOME@@ ;	export MOZILLA_HOME
NS_PLUGINS_DIR=@@NS_PLUGINS_DIR@@;	export NS_PLUGINS_DIR
XNLSPATH=${MOZILLA_HOME}/nls ;		export XNLSPATH
XKEYSYMDB=${MOZILLA_HOME}/XKeysymDB ;	export XKEYSYMDB
NPX_PLUGIN_PATH=${NS_PLUGINS_DIR}:${MOZILLA_HOME}/plugins:${HOME}/.netscape/plugins ;	export NPX_PLUGIN_PATH

exec ${MOZILLA_HOME}/netscape "$@"
