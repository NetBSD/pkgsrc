#!/bin/sh
#
# $NetBSD: gdm,v 1.1 2001/07/23 00:59:20 wiz Exp $
#

# PROVIDE: gdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

. /etc/rc.subr

name="gdm"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/${name}.pid"
required_files="@PREFIX@/etc/gdm/gdm.conf"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
