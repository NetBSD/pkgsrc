$NetBSD: patch-src_buildtools_buildtools.pro,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/buildtools/buildtools.pro.orig
+++ src/buildtools/buildtools.pro
@@ -1,6 +1,6 @@
 TEMPLATE = subdirs
 
-linux {
+unix {
     # configure_host.pro and configure_target.pro are phony pro files that
     # extract things like compiler and linker from qmake.
     # Only used on Linux as it is only important for cross-building and alternative compilers.
