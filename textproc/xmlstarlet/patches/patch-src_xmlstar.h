$NetBSD: patch-src_xmlstar.h,v 1.1 2025/05/01 15:16:21 tnn Exp $

* sprinkle some const to appease clang and libxml2

--- src/xmlstar.h.orig	2025-05-01 14:48:24.749356766 +0000
+++ src/xmlstar.h
@@ -32,7 +32,7 @@ typedef struct _errorInfo {
     ErrorStop stop;
 } ErrorInfo;
 
-void reportError(void *ptr, xmlErrorPtr error);
+void reportError(void *ptr, const struct _xmlError *);
 void suppressErrors(void);
 
 typedef struct _gOptions {
