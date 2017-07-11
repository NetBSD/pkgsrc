$NetBSD: patch-net_resolver.h,v 1.1 2017/07/11 14:56:37 schmonz Exp $

Include missing AF_INET definition to fix NetBSD build.

--- net/resolver.h.orig	2017-04-24 02:19:20.000000000 +0000
+++ net/resolver.h
@@ -23,6 +23,7 @@
 
 #include <cstring>
 #include "safenetdb.h"
+#include "safesyssocket.h"
 #include "str.h"
 #include "xapian/error.h"
 
