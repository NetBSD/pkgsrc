$NetBSD: patch-src_scanner.cc,v 1.1 2023/05/08 17:24:29 he Exp $

Include <stdint.h> for UINT16_max etc.

--- src/scanner.cc.orig	2022-06-21 19:02:51.000000000 +0000
+++ src/scanner.cc
@@ -4,6 +4,9 @@
 #include <cstring>
 #include <cassert>
 #include <stdio.h>
+
+#include <stdint.h>	// for UINT16_MAX etc.
+
 namespace {
 
 using std::vector;
