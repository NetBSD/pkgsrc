$NetBSD: patch-src_xml.c,v 1.1 2025/05/01 15:16:21 tnn Exp $

* sprinkle some const to appease clang and libxml2

--- src/xml.c.orig	2025-05-01 14:50:59.284458064 +0000
+++ src/xml.c
@@ -104,7 +104,7 @@ void reportGenericError(void* ctx, const
 /* by default all errors are reported */
 static ErrorInfo errorInfo = { NULL, NULL, VERBOSE, CONTINUE };
 
-void reportError(void *ptr, xmlErrorPtr error)
+void reportError(void *ptr, const struct _xmlError *error)
 {
     ErrorInfo *errorInfo = (ErrorInfo*) ptr;
     assert(errorInfo);
