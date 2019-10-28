$NetBSD: patch-config.tests_wayland__scanner_wayland__scanner.pro,v 1.1 2019/10/28 21:35:43 nia Exp $

Fix path to QMAKE_WAYLAND_SCANNER.

--- config.tests/wayland_scanner/wayland_scanner.pro.orig	2019-08-13 09:25:25.000000000 +0000
+++ config.tests/wayland_scanner/wayland_scanner.pro
@@ -1,10 +1,10 @@
 TARGET = wayland_scanner
 
-isEmpty(QMAKE_WAYLAND_SCANNER):error("QMAKE_WAYLAND_SCANNER not defined for this mkspec")
-
 # Input
 SOURCES += main.cpp
 
+QMAKE_WAYLAND_SCANNER = @PREFIX@/bin/wayland-scanner
+
 wayland-check-header.name = wayland ${QMAKE_FILE_BASE}
 wayland-check-header.input = WAYLANDCHECKSOURCES
 wayland-check-header.variable_out = HEADERS
