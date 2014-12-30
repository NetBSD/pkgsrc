$NetBSD: patch-src_corelib_global_qsystemdetection.h,v 1.1 2014/12/30 17:23:46 adam Exp $

* Add Interix support

--- src/corelib/global/qsystemdetection.h.orig	2013-11-27 01:01:15.000000000 +0000
+++ src/corelib/global/qsystemdetection.h
@@ -68,6 +68,7 @@
      NETBSD   - NetBSD
      OPENBSD  - OpenBSD
      BSDI     - BSD/OS
+     INTERIX  - Interix
      IRIX     - SGI Irix
      OSF      - HP Tru64 UNIX
      SCO      - SCO OpenServer 5
@@ -151,6 +152,9 @@
 #elif defined(__bsdi__)
 #  define Q_OS_BSDI
 #  define Q_OS_BSD4
+#elif defined(__INTERIX)
+#  define Q_OS_INTERIX
+#  define Q_OS_BSD4
 #elif defined(__sgi)
 #  define Q_OS_IRIX
 #elif defined(__osf__)
