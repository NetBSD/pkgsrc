#!/bin/sh
#
# $NetBSD: navigator.sh,v 1.3 1999/09/04 16:38:30 jlam Exp $
#
MOZILLA_HOME=@@MOZILLA_HOME@@ ;	export MOZILLA_HOME
NS_PLUGINS_DIR=@@NS_PLUGINS_DIR@@;	export NS_PLUGINS_DIR
XNLSPATH=${MOZILLA_HOME}/nls ;		export XNLSPATH
XKEYSYMDB=${MOZILLA_HOME}/XKeysymDB ;	export XKEYSYMDB
NPX_PLUGIN_PATH=${NS_PLUGINS_DIR}:${MOZILLA_HOME}/plugins:${HOME}/.netscape/plugins ;	export NPX_PLUGIN_PATH

exec ${MOZILLA_HOME}/netscape "$@"
