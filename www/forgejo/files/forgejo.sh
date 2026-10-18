#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: forgejo.sh,v 1.1 2026/10/18 08:23:58 khorben Exp $
#
# PROVIDE: forgejo
# REQUIRE: DAEMON
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start forgejo:
#
# forgejo=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="forgejo"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/conf/app.ini"
command="@PREFIX@/sbin/forgejo"
command_args="--config @PKG_SYSCONFDIR@/conf/app.ini web > /dev/null &"

forgejo_env="FORGEJO_WORK_DIR=@FORGEJO_SHARE_DIR@"
forgejo_env="${forgejo_env} FORGEJO_CUSTOM=@PKG_SYSCONFDIR@"
forgejo_env="${forgejo_env} HOME=@FORGEJO_USER_HOME@"
forgejo_env="${forgejo_env} USER=@FORGEJO_USER@"

forgejo_user="@FORGEJO_USER@"
forgejo_group="@FORGEJO_GROUP@"

cd /

load_rc_config $name
run_rc_command "$1"
