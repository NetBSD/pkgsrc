$NetBSD: patch-system.mk,v 1.1.1.1 2012/01/08 15:22:14 wiz Exp $

Adapt for pkgsrc.

--- system.mk.orig	2011-10-29 18:27:06.000000000 +0000
+++ system.mk
@@ -8,7 +8,8 @@
 
 # Installation path prefix. Unless you know what you're doing, the default
 # of /usr/local is likely the correct choice.
-PREFIX=/usr/local
+# set by pkgsrc
+#PREFIX=/usr/local
 
 # Unless you are creating a package conforming to some OS's standards, you
 # probably do not want to modify the following directories:
@@ -16,11 +17,12 @@ PREFIX=/usr/local
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
@@ -53,7 +55,8 @@ LOCALEDIR=$(PREFIX)/share/locale
 
 # Flags to link with libdl. Even if PRELOAD_MODULES=1, you may need this
 # setting (for e.g. Lua, when not instructed by pkg-config).
-DL_LIBS=-ldl
+# set by pkgsrc
+#DL_LIBS=-ldl
 
 
 ##
@@ -66,8 +69,8 @@ DL_LIBS=-ldl
 
 # Default to paths and names that should work for a build installed from the
 # official Lua 5.1 source tarball.
-LUA_DIR=/usr/local
-LUA_LIBS=-L$(LUA_DIR)/lib -llua
+LUA_DIR=$(PREFIX)
+LUA_LIBS=${LINKER_RPATH_FLAG}$(LUA_DIR)/lib -L$(LUA_DIR)/lib -llua
 LUA_INCLUDES = -I$(LUA_DIR)/include
 LUA=$(LUA_DIR)/bin/lua
 LUAC=$(LUA_DIR)/bin/luac
@@ -100,11 +103,12 @@ endif # LUA_MANUAL
 ##
 
 # Paths
-X11_PREFIX=/usr/X11R6
+# set by pkgsrc
+#X11_PREFIX=/usr/X11R6
 # SunOS/Solaris
 #X11_PREFIX=/usr/openwin
 
-X11_LIBS=-L$(X11_PREFIX)/lib -lX11 -lXext
+X11_LIBS=${LINKER_RPATH_FLAG}${X11_PREFIX}/lib -L$(X11_PREFIX)/lib -lX11 -lXext
 X11_INCLUDES=-I$(X11_PREFIX)/include
 
 # XFree86 libraries up to 4.3.0 have a bug that can cause a segfault.
@@ -132,7 +136,7 @@ DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WOR
 #DEFINES += -DCF_NO_LOCALE -DCF_NO_GETTEXT
 
 # On some other systems you may need to explicitly link against libintl.
-#EXTRA_LIBS += -lintl
+EXTRA_LIBS += -lintl
 # You may also need to give the location of its headers. The following
 # should work on Mac OS X (which needs the above option as well) with
 # macports.
@@ -146,7 +150,7 @@ DEFINES += -DCF_XFREE86_TEXTPROP_BUG_WOR
 # You may uncomment this if you know that your system C libary provides
 # asprintf and  vasprintf. (GNU libc does.) If HAS_SYSTEM_ASPRINTF is not
 # defined, an implementation provided in libtu/sprintf_2.2/ is used. 
-#HAS_SYSTEM_ASPRINTF=1
+HAS_SYSTEM_ASPRINTF=1
 
 # The following setting is needed with GNU libc for clock_gettime and the
 # monotonic clock. Other systems may not need it, or may not provide a
