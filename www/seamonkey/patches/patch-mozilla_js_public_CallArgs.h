$NetBSD: patch-mozilla_js_public_CallArgs.h,v 1.1 2015/09/21 05:03:45 ryoon Exp $

--- mozilla/js/public/CallArgs.h.orig	2015-09-02 09:27:18.000000000 +0000
+++ mozilla/js/public/CallArgs.h
@@ -344,7 +344,7 @@ class MOZ_STACK_CLASS CallArgs : public 
      * Returns true if there are at least |required| arguments passed in. If
      * false, it reports an error message on the context.
      */
-    bool requireAtLeast(JSContext* cx, const char* fnname, unsigned required);
+    JS_PUBLIC_API(bool) requireAtLeast(JSContext* cx, const char* fnname, unsigned required);
 
 };
 
