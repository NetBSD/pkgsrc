$NetBSD: patch-leapsinstall.sh,v 1.2 2020/11/07 13:49:16 schmonz Exp $

Support PKG_SYSCONFDIR.

--- leapsinstall.sh.orig	2020-04-10 03:54:15.000000000 +0000
+++ leapsinstall.sh
@@ -1,3 +1,3 @@
-./leapsunpack -a | ./leapsecs > ${1-/etc/leapsecs.dat}.tmp
-chmod 0644 ${1-/etc/leapsecs.dat}.tmp
-mv -f ${1-/etc/leapsecs.dat}.tmp ${1-/etc/leapsecs.dat}
+leapsunpack -a | leapsecs > ${1-@PKG_SYSCONFDIR@/leapsecs.dat}.tmp
+chmod 0644 ${1-@PKG_SYSCONFDIR@/leapsecs.dat}.tmp
+mv -f ${1-@PKG_SYSCONFDIR@/leapsecs.dat}.tmp ${1-@PKG_SYSCONFDIR@/leapsecs.dat}
