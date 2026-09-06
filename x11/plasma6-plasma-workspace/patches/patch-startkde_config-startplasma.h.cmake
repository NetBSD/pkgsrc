$NetBSD: patch-startkde_config-startplasma.h.cmake,v 1.2 2026/09/06 10:23:34 markd Exp $

From FreeBSD to fix XDG_CONFIG_DIRS

--- startkde/config-startplasma.h.cmake.orig	2026-08-04 09:25:56.000000000 +0000
+++ startkde/config-startplasma.h.cmake
@@ -2,6 +2,7 @@
 
 #define CMAKE_INSTALL_FULL_BINDIR "@CMAKE_INSTALL_FULL_BINDIR@"
 #define KDE_INSTALL_FULL_DATAROOTDIR "@KDE_INSTALL_FULL_DATAROOTDIR@"
+#define KDE_INSTALL_FULL_CONFDIR "@KDE_INSTALL_FULL_CONFDIR@"
 #define CMAKE_INSTALL_FULL_LIBEXECDIR "@CMAKE_INSTALL_FULL_LIBEXECDIR@"
 #define KWIN_WAYLAND_BIN_PATH "@KWIN_WAYLAND_BIN_PATH@"
 
