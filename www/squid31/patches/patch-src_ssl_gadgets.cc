$NetBSD: patch-src_ssl_gadgets.cc,v 1.1.2.2 2011/08/31 09:19:24 sbd Exp $

Include correct config.h as there might be other impostors wandering around.

--- src/ssl/gadgets.cc.orig	2011-07-20 10:55:12.000000000 +0000
+++ src/ssl/gadgets.cc
@@ -3,5 +3,5 @@
  */
 
-#include "config.h"
+#include "include/config.h"
 #include "ssl/gadgets.h"
 
