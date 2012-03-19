$NetBSD: patch-ksysguard_ksysguardd_NetBSD_CPU.h,v 1.1 2012/03/19 19:44:03 markd Exp $

--- ksysguard/ksysguardd/NetBSD/CPU.h.save	2006-10-26 15:12:41.000000000 +1300
+++ ksysguard/ksysguardd/NetBSD/CPU.h
@@ -37,6 +37,10 @@ void printCPUSys(const char* cmd);
 void printCPUSysInfo(const char* cmd);
 void printCPUIdle(const char* cmd);
 void printCPUIdleInfo(const char* cmd);
+void printCPUIntr(const char* cmd);
+void printCPUIntrInfo(const char* cmd);
+void printCPUWait(const char* cmd);
+void printCPUWaitInfo(const char* cmd);
 void printCPUxUser(const char* cmd);
 void printCPUxUserInfo(const char* cmd);
 void printCPUxNice(const char* cmd);
