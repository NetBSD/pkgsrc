#!/bin/sh
#
# $NetBSD: squid.sh,v 1.8 2001/05/10 21:58:02 tron Exp $
#
# PROVIDE: squid
# REQUIRE: DAEMON
# KEYWORD: shutdown

name="squid"
command="@PREFIX@/sbin/${name}"
required_files="/etc/squid.conf"
command_args="-Y -f $required_files"

if [ ! -d /etc/rc.d ]
then
	@ECHO@ -n ' ${name}'
	exec ${command} ${command_args}
fi

. /etc/rc.subr

extra_commands="reload"

if [ "$1" = rotate ]
then
 exec ${command} -k rotate
fi

load_rc_config $name
run_rc_command "$1"
