$NetBSD: patch-src_FbTk_KeyUtil.cc,v 1.1 2011/11/25 22:25:31 joerg Exp $

--- src/FbTk/KeyUtil.cc.orig	2011-11-25 17:42:18.000000000 +0000
+++ src/FbTk/KeyUtil.cc
@@ -25,6 +25,7 @@
 #include "App.hh"
 
 #include <string>
+#include <strings.h>
 
 namespace {
 
