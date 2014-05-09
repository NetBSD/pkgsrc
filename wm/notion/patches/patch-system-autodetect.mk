$NetBSD: patch-system-autodetect.mk,v 1.4 2014/05/09 16:20:24 wiz Exp $

Adapt for pkgsrc.

--- system-autodetect.mk.orig	2014-01-09 19:02:16.000000000 +0000
+++ system-autodetect.mk
@@ -63,7 +63,8 @@ endif
 
 # Flags to link with libdl. Even if PRELOAD_MODULES=1, you may need this
 # setting (for e.g. Lua, when not instructed by pkg-config).
-DL_LIBS=-ldl
+# set by pkgsrc
+#DL_LIBS=-ldl
 
 
 ##
@@ -109,7 +110,7 @@ DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WOR
 #DEFINES += -DCF_NO_LOCALE -DCF_NO_GETTEXT
 
 # On some other systems you may need to explicitly link against libintl.
-#EXTRA_LIBS += -lintl
+EXTRA_LIBS += -lintl
 # You may also need to give the location of its headers. The following
 # should work on Mac OS X (which needs the above option as well) with
 # macports.
