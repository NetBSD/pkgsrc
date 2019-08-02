#!@RCD_SCRIPTS_SHELL@

# PROVIDE: grafana
# REQUIRE: DAEMON
# KEYWORD: shutdown

if [ -f /etc/rc.subr ]; then
	. /etc/rc.subr
fi

name="grafana"
rcvar=$name
grafana_user="@GRAFANA_USER@"
grafana_group="@GRAFANA_GROUP@"
grafana_home="@PREFIX@/share/${name}"
pidfile="@VARBASE@/run/${name}.pid"
command="@PREFIX@/bin/grafana-server"
command_args="-homepath ${grafana_home} -config @PKG_SYSCONFDIR@/grafana.conf -pidfile ${pidfile} < /dev/null > /dev/null 2>&1 &"
start_precmd="grafana_precmd"

grafana_precmd() {
	if [ ! -r "${pidfile}" ]; then
		touch "${pidfile}"
		chown "${grafana_user}:${grafana_group}" "${pidfile}"
		chmod 644 "${pidfile}"
	fi
}

if [ -f /etc/rc.subr -a -d /etc/rc.d -a -f /etc/rc.d/DAEMON ]; then
	load_rc_config $name
	run_rc_command "$1"
else
	if [ -f /etc/rc.conf ]; then
		. /etc/rc.conf
	fi
	case "$1" in
	start)
		if [ -r "${pidfile}" ]; then
			@ECHO@ "Already running ${name}."
		else
			@ECHO@ "Starting ${name}."
			eval ${command} ${command_args}
		fi
		;;
	stop)
		if [ -r "${pidfile}" ]; then
			@ECHO@ "Stopping ${name}."
			kill `@CAT@ "${pidfile}"` && @RM@ "${pidfile}"
		fi
		;;
	*)
		@ECHO@ "Usage: $0 {start|stop}" 1>&2
		exit 10
		;;
	esac
fi
