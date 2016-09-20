$NetBSD: patch-include_ttyutils.h,v 1.1 2016/09/20 08:00:51 wiz Exp $

Define values if missing.

--- include/ttyutils.h.orig	2016-01-06 10:50:36.000000000 +0000
+++ include/ttyutils.h
@@ -114,6 +114,13 @@ static inline void reset_virtual_console
 # define FFDLY 0
 #endif
 
+#ifndef TAB0
+#define TAB0 0
+#endif
+#ifndef TABDLY
+#define TABDLY 0
+#endif
+
 	tp->c_iflag |=  (BRKINT | ICRNL | IMAXBEL);
 	tp->c_iflag &= ~(IGNBRK | INLCR | IGNCR | IXOFF | IUCLC | IXANY | ISTRIP);
 	tp->c_oflag |=  (OPOST | ONLCR | NL0 | CR0 | TAB0 | BS0 | VT0 | FF0);
