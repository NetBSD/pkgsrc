$NetBSD: patch-xpcom_base_nsStackWalk.cpp,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- xpcom/base/nsStackWalk.cpp.orig	2014-01-28 04:04:07.000000000 +0000
+++ xpcom/base/nsStackWalk.cpp
@@ -853,7 +853,7 @@ void DemangleSymbol(const char * aSymbol
 }
 
 
-#if NSSTACKWALK_SUPPORTS_SOLARIS
+#if notNSSTACKWALK_SUPPORTS_SOLARIS
 
 /*
  * Stack walking code for Solaris courtesy of Bart Smaalder's "memtrak".
