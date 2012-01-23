$NetBSD: patch-kjs_lookup.h,v 1.1 2012/01/23 08:14:02 joerg Exp $

--- kjs/lookup.h.orig	2012-01-22 20:17:34.000000000 +0000
+++ kjs/lookup.h
@@ -23,6 +23,7 @@
 #ifndef _KJSLOOKUP_H_
 #define _KJSLOOKUP_H_
 
+#include "JSVariableObject.h"
 #include "interpreter.h"
 #include "identifier.h"
 #include "object.h"
