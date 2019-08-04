#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: gitea.sh,v 1.2 2019/08/04 12:26:59 nia Exp $
#
# PROVIDE: gitea
# REQUIRE: DAEMON

. /etc/rc.subr

name="gitea"
rcvar=${name}
required_files="@PKG_SYSCONFDIR@/conf/app.ini"
command="@PREFIX@/sbin/gitea"
command_args="--config @PKG_SYSCONFDIR@/conf/app.ini web &"

gitea_env="GITEA_WORK_DIR=@GITEA_SHARE_DIR@"
gitea_env="${gitea_env} GITEA_CUSTOM=@PKG_SYSCONFDIR@"
gitea_env="${gitea_env} HOME=@GITEA_USER_HOME@"
gitea_env="${gitea_env} USER=@GITEA_USER@"

gitea_user="@GITEA_USER@"
gitea_group="@GITEA_GROUP@"

load_rc_config $name
run_rc_command "$1"
