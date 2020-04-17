$NetBSD: patch-libptytty_src_logging.C,v 1.1 2020/04/17 08:43:46 jperkin Exp $

Support SunOS lastlog file.

--- libptytty/src/logging.C.orig	2014-11-16 12:22:34.000000000 +0000
+++ libptytty/src/logging.C
@@ -76,6 +76,8 @@
 #  define LASTLOG_FILE _PATH_LASTLOG
 # elif defined(PT_LASTLOG_FILE)
 #  define LASTLOG_FILE PT_LASTLOG_FILE
+# elif defined(__sun)
+#  define LASTLOG_FILE "/var/adm/lastlog"
 # endif
 #endif
 #if !defined(LASTLOGX_FILE)
