#!@RCD_SCRIPTS_SHELL@
#
# PROVIDE: sydent
# REQUIRE: DAEMON

if [ -f /etc/rc.subr ]; then
  . /etc/rc.subr
fi

name="sydent"
rcvar="sydent"
procname="@PYTHONBIN@"
ctl_command="@PYTHONBIN@"
conf_file="@PKG_SYSCONFDIR@/sydent.conf"
required_files="$conf_file"
pidfile="@SYDENT_DATA@/sydent.pid"
: ${sydent_user:=@SYDENT_USER@}

start_cmd="@SU@ -m ${sydent_user} -c \
    'cd @PKG_SYSCONFDIR@ && ${ctl_command} -m sydent.sydent 2>&- 1>&- 0<&- &'"

load_rc_config $name
run_rc_command "$1"
