$NetBSD: patch-src_scanner.cc,v 1.1 2023/05/08 17:38:25 he Exp $

--- src/scanner.cc.orig	2021-03-04 22:11:18.000000000 +0000
+++ src/scanner.cc
@@ -6,6 +6,8 @@
 #include <cstring>
 #include "tag.h"
 
+#include <stdint.h> // for UINT16_MAX etc.
+
 namespace {
 
 using std::vector;
