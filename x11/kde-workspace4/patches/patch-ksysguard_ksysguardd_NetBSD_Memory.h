$NetBSD: patch-ksysguard_ksysguardd_NetBSD_Memory.h,v 1.1 2012/03/19 19:44:03 markd Exp $

--- ksysguard/ksysguardd/NetBSD/Memory.h.orig	2008-01-05 12:55:45.000000000 +1300
+++ ksysguard/ksysguardd/NetBSD/Memory.h
@@ -41,9 +41,18 @@ void printExecpages(const char* cmd);
 void printExecpagesInfo(const char* cmd);
 void printFilepages(const char* cmd);
 void printFilepagesInfo(const char* cmd);
+void printAnonpages(const char* cmd);
+void printAnonpagesInfo(const char* cmd);
 void printSwapUsed(const char* cmd);
 void printSwapUsedInfo(const char* cmd);
 void printSwapFree(const char* cmd);
 void printSwapFreeInfo(const char* cmd);
 
+void printAppl(const char* cmd);
+void printApplInfo(const char* cmd);
+void printBuffers(const char* cmd);
+void printBuffersInfo(const char* cmd);
+void printCached(const char* cmd);
+void printCachedInfo(const char* cmd);
+
 #endif
