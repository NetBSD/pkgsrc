$NetBSD: patch-system-autodetect.mk,v 1.2 2013/10/20 17:48:54 joerg Exp $

Adapt for pkgsrc.

--- system-autodetect.mk.orig	2013-03-02 21:02:30.000000000 +0000
+++ system-autodetect.mk
@@ -9,7 +9,7 @@
 # Installation path prefix. Unless you know what you're doing, the default
 # of /usr/local is likely the correct choice.
 #DIST: PREFIX=/usr/local
-PREFIX=/usr/local
+#PREFIX=/usr/local
 
 # Unless you are creating a package conforming to some OS's standards, you
 # probably do not want to modify the following directories:
@@ -17,11 +17,12 @@ PREFIX=/usr/local
 # Main binaries
 BINDIR=$(PREFIX)/bin
 # Configuration .lua files
+EXAMPLEDIR=$(PREFIX)/share/examples/notion
 ETCDIR=$(PREFIX)/etc/notion
 # Some .lua files and ion-* shell scripts
 SHAREDIR=$(PREFIX)/share/notion
 # Manual pages
-MANDIR=$(PREFIX)/share/man
+MANDIR=$(PREFIX)/man
 # Some documents
 DOCDIR=$(PREFIX)/share/doc/notion
 # Nothing at the moment
@@ -54,7 +55,8 @@ LOCALEDIR=$(PREFIX)/share/locale
 
 # Flags to link with libdl. Even if PRELOAD_MODULES=1, you may need this
 # setting (for e.g. Lua, when not instructed by pkg-config).
-DL_LIBS=-ldl
+# set by pkgsrc
+#DL_LIBS=-ldl
 
 
 ##
@@ -67,8 +69,8 @@ DL_LIBS=-ldl
 
 # Default to paths and names that should work for a build installed from the
 # official Lua 5.1 source tarball.
-LUA_DIR=/usr/local
-LUA_LIBS=-L$(LUA_DIR)/lib -llua
+LUA_DIR=$(PREFIX)
+LUA_LIBS=${COMPILER_RPATH_FLAG}$(LUA_DIR)/lib -L$(LUA_DIR)/lib -llua
 LUA_INCLUDES = -I$(LUA_DIR)/include
 
 ifneq ($(shell which lua),)
@@ -132,11 +134,12 @@ endif # lua manual
 ##
 
 # Paths
-X11_PREFIX=/usr/X11R6
+# set by pkgsrc
+#X11_PREFIX=/usr/X11R6
 # SunOS/Solaris
 #X11_PREFIX=/usr/openwin
 
-X11_LIBS=-L$(X11_PREFIX)/lib -lX11 -lXext
+X11_LIBS=${COMPILER_RPATH_FLAG}${X11_PREFIX}/lib -L$(X11_PREFIX)/lib -lX11 -lXext
 X11_INCLUDES=-I$(X11_PREFIX)/include
 
 # XFree86 libraries up to 4.3.0 have a bug that can cause a segfault.
@@ -164,7 +167,7 @@ DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WOR
 #DEFINES += -DCF_NO_LOCALE -DCF_NO_GETTEXT
 
 # On some other systems you may need to explicitly link against libintl.
-#EXTRA_LIBS += -lintl
+EXTRA_LIBS += -lintl
 # You may also need to give the location of its headers. The following
 # should work on Mac OS X (which needs the above option as well) with
 # macports.
