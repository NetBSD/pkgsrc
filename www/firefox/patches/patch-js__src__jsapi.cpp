$NetBSD: patch-js__src__jsapi.cpp,v 1.2 2013/06/26 11:32:12 ryoon Exp $

From bugzilla, bug 840242, attachment v1
Use the runtime page size to control arena decommit.

As a side effect, this removes the hard coded page-size == 4k requirement.


diff js/src/jsapi.cpp js/src/jsapi.cpp
--- js/src/jsapi.cpp.orig	2013-06-17 22:13:11.000000000 +0000
+++ js/src/jsapi.cpp
@@ -1131,8 +1131,6 @@ JS_NewRuntime(uint32_t maxbytes, JSUseHe
 #undef MSG_DEF
 #endif /* DEBUG */
 
-        InitMemorySubsystem();
-
         if (!js::TlsPerThreadData.init())
             return NULL;
 
