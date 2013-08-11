$NetBSD: patch-mozilla_xpcom_base_nsStackWalk.cpp,v 1.1 2013/08/11 03:18:46 ryoon Exp $

--- mozilla/xpcom/base/nsStackWalk.cpp.orig	2013-08-04 03:05:53.000000000 +0000
+++ mozilla/xpcom/base/nsStackWalk.cpp
@@ -853,7 +853,7 @@ void DemangleSymbol(const char * aSymbol
 }
 
 
-#if NSSTACKWALK_SUPPORTS_SOLARIS
+#if notNSSTACKWALK_SUPPORTS_SOLARIS
 
 /*
  * Stack walking code for Solaris courtesy of Bart Smaalder's "memtrak".
