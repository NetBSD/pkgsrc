#!/bin/sh
#
# $NetBSD: anubis.sh,v 1.1 2025/05/22 15:14:15 ryoon Exp $
#
# PROVIDE: anubis
# REQUIRE: DAEMON
#
# anubis=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="anubis"
rcvar=${name}
command="@PREFIX@/bin/${name}"
pidfile="@VARBASE@/run/${name}/${name}.pid"
anubis_user="@APACHE_USER@"
anubis_group="@APACHE_GROUP@"
start_precmd="anubis_precmd"
start_cmd="anubis_start"
start_postcmd="anubis_poststart"

anubis_precmd()
{
	if [ ! -d @VARBASE@/run/${name} ]; then
		@MKDIR@ @VARBASE@/run/${name}
		@CHOWN@ ${anubis_user}:${anubis_group} @VARBASE@/run/${name}
	fi
}

anubis_start()
{
	@SU@ -m ${anubis_user} -c "${command} -serve-robots-txt" >> @VARBASE@/log/anubis.log 2>&1 &
}

anubis_poststart() {
	echo $! > ${pidfile}
}

anubis_stop()
{
	kill -HUP $(check_pidfile $pidfile $name)
}

load_rc_config $name
run_rc_command "$1"
