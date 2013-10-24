$NetBSD: patch-defaults_Solaris_set.csh,v 1.1 2013/10/24 10:10:21 jperkin Exp $

Use pkgsrc variables.

--- defaults/Solaris/set.csh.orig	1999-07-28 15:24:23.000000000 +0000
+++ defaults/Solaris/set.csh
@@ -1,8 +1,8 @@
-set CAT = /bin/cat
-set CC = /opt/SUNWspro/bin/cc
+set CAT = cat
+set CC = cc
 set CFLAGS = "-O"
-set INSTALL = "/usr/ucb/install -c"
-set STRIP = /usr/ccs/bin/strip
-set INCLUDES = "-I/usr/openwin/include"
-set LDLIBS = "-lm -L/usr/openwin/lib -lX11"
+set INSTALL = false
+set STRIP = strip
+set INCLUDES = "-I@X11BASE@/include"
+set LDLIBS = "-lm -L@X11BASE@/lib -Wl,-R@X11BASE@/lib -lX11"
 set MORELIBS = "-lsocket -lnsl"
