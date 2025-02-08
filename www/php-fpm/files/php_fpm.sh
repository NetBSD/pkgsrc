#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: php_fpm.sh,v 1.4 2025/02/08 03:22:19 taca Exp $
#
# PROVIDE: php_fpm
# REQUIRE: DAEMON
#
# Consider installing pkgtools/rc.subr in unprivileged.
#
# You will need to set some variables in @SYSCONFBASE@/rc.conf to start php-fpm:
#
# php_fpm=YES

$_rc_subr_loaded . @SYSCONFBASE@/rc.subr

name="php_fpm@PHP_VER@"
rcvar=${name}
command="@PREFIX@/sbin/php-fpm@PHP_VER@"
required_files="@PKG_SYSCONFDIR@/php-fpm.conf"
pidfile="@VARBASE@/run/php-fpm@PHP_VER@.pid"
sig_reload="USR2"
extra_commands="reload"

load_rc_config $name
run_rc_command "$1"
