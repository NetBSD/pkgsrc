#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: kdm.sh,v 1.3 2004/05/31 12:21:06 markd Exp $
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
required_files="@PKG_SYSCONFDIR@/kdm/kdmrc"
command_args="-config ${required_files}"

if [ -f /etc/rc.subr ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	echo -n " ${name}"
	${command} ${kdm_flags} ${command_args}
fi
