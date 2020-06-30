$NetBSD: patch-leapsinstall.sh,v 1.1 2020/06/30 17:29:12 schmonz Exp $

Support PKG_SYSCONFDIR.

--- leapsinstall.sh.orig	2003-12-30 21:18:29.000000000 +0000
+++ leapsinstall.sh
@@ -1,4 +1,4 @@
 umask 022
-HOME/leapsunpack -a | HOME/leapsecs > ${1-/etc/leapsecs.dat}.tmp
-mv ${1-/etc/leapsecs.dat}.tmp ${1-/etc/leapsecs.dat}
-chmod 0644 ${1-/etc/leapsecs.dat}
+HOME/leapsunpack -a | HOME/leapsecs > ${1-@PKG_SYSCONFDIR@/leapsecs.dat}.tmp
+mv ${1-@PKG_SYSCONFDIR@/leapsecs.dat}.tmp ${1-@PKG_SYSCONFDIR@/leapsecs.dat}
+chmod 0644 ${1-@PKG_SYSCONFDIR@/leapsecs.dat}
