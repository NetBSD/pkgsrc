#!/bin/sh
#
# $NetBSD: gdm.sh,v 1.1 2004/01/20 13:41:06 xtraeme Exp $
#

# PROVIDE: gdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

. /etc/rc.subr

name="gdm"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="@LOCALSTATEDIR@/run/${name}.pid"
required_files="@PKG_SYSCONFDIR@/gdm/gdm.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
