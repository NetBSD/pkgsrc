$NetBSD: patch-platform_build_autoconf_compiler-opts.m4,v 1.1 2026/09/22 14:38:43 nia Exp $

This change is necessary for compatibility with i586-class CPUs
(AMD Geode, Vortex86), which NetBSD targets with its i386 port.

https://forum.palemoon.org/viewtopic.php?f=40&t=33775

--- platform/build/autoconf/compiler-opts.m4.orig	2026-09-20 10:02:35.865353170 +0000
+++ platform/build/autoconf/compiler-opts.m4
@@ -179,13 +179,6 @@ if test "$GNU_CC"; then
     CFLAGS="$CFLAGS -fno-math-errno -pipe"
     CXXFLAGS="$CXXFLAGS -fno-exceptions -fno-math-errno -pipe"
 
-    case "${host_cpu}" in
-      i*86)
-        CFLAGS="$CFLAGS -msse2 -mfpmath=sse"
-        CXXFLAGS="$CXXFLAGS -msse2 -mfpmath=sse"
-        ;;
-    esac
-
     if test -z "$CLANG_CC"; then
         case "$CC_VERSION" in
         4.* | 5.* | 6.* | 7.* | 8.*)
