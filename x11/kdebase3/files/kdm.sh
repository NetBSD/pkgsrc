#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: kdm.sh,v 1.2 2004/05/01 11:14:41 xtraeme Exp $
#

# PROVIDE: kdm
# REQUIRE: DAEMON LOGIN wscons
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="kdm"
rcvar=$name
command="@PREFIX@/bin/${name}"
pidfile="/var/run/kdm.pid"
required_files="@PREFIX@/share/kde/config/kdm/kdmrc"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${kdm_flags} ${command_args}
fi
