#!@RCD_SCRIPTS_SHELL@

# REQUIRE: DAEMON
# PROVIDE: goaccess
# KEYWORD: shutdown

$_rc_subr_loaded . /etc/rc.subr

name="goaccess"
command="@PREFIX@/bin/$name"
pidfile="/var/run/goaccess/$name.pid"
start_precmd="goaccess_prestart"
stop_postcmd="goaccess_poststop"

: ${goaccess_username:=@GOACCESS_USER@}
: ${goaccess_outfile:=/var/www/$name.html}

goaccess_prestart()
{
	if [ -z "$goaccess_logfile" ]; then
		echo "goacess_logfile is not set" >&2
		return 1
	fi

	mkdir -p /var/run/goaccess
	chown $goaccess_username /var/run/goaccess

	rc_flags="-o $goaccess_outfile"
	rc_flags="--real-time-html $rc_flags"
	if [ -n "$goaccess_username" ]; then
		rc_flags="--user-name $goaccess_username $rc_flags"
	fi
	rc_flags="--daemonize --pid-file $pidfile $rc_flags"

	rc_flags="$rc_flags $goaccess_logfile"
}

goaccess_poststop()
{
	checkyesno goaccess_logrotate || return 0
	[ -n "$goaccess_logfile " ] || return 0

	echo "Rotating $goaccess_logfile"
	if [ -x /usr/bin/newsyslog ]; then
		/usr/bin/newsyslog -F $goaccess_logfile
	else
		echo "No logrotate mechanism!" >&2
	fi
}

load_rc_config $name
run_rc_command "$1"
