$NetBSD: patch-mozilla_js_src_jsapi.cpp,v 1.1 2013/07/12 12:24:10 ryoon Exp $

--- mozilla/js/src/jsapi.cpp.orig	2013-06-20 04:35:08.000000000 +0000
+++ mozilla/js/src/jsapi.cpp
@@ -1131,8 +1131,6 @@ JS_NewRuntime(uint32_t maxbytes, JSUseHe
 #undef MSG_DEF
 #endif /* DEBUG */
 
-        InitMemorySubsystem();
-
         if (!js::TlsPerThreadData.init())
             return NULL;
 
