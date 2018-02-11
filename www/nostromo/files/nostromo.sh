#!/bin/sh
#
# $NetBSD: nostromo.sh,v 1.1 2018/02/11 13:56:21 ast Exp $
#

# PROVIDE: nostromo
# REQUIRE: DAEMON

. /etc/rc.subr

name="nostromo"
rcvar=$name
command="@PREFIX@/sbin/nhttpd"
required_files="@PREFIX@/nostromo/conf/nhttpd.conf"

load_rc_config $name
run_rc_command "$1"
