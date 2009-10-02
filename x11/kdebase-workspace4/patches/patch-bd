$NetBSD: patch-bd,v 1.1.1.1 2009/10/02 19:37:22 markd Exp $

--- ksysguard/ksysguardd/NetBSD/Memory.c.orig	2008-01-05 12:55:45.000000000 +1300
+++ ksysguard/ksysguardd/NetBSD/Memory.c
@@ -49,10 +49,13 @@ static size_t Inactive = 0;
 static size_t Wired = 0;
 static size_t Execpages = 0;
 static size_t Filepages = 0;
+static size_t Anonpages = 0;
 static size_t STotal = 0;
 static size_t SFree = 0;
 static size_t SUsed = 0;
 
+static size_t Appl = 0;
+
 void
 initMemory(struct SensorModul* sm)
 {
@@ -63,8 +66,13 @@ initMemory(struct SensorModul* sm)
 	registerMonitor("mem/physical/wired", "integer", printWired, printWiredInfo, sm);
 	registerMonitor("mem/physical/execpages", "integer", printExecpages, printExecpagesInfo, sm);
 	registerMonitor("mem/physical/filepages", "integer", printFilepages, printFilepagesInfo, sm);
+	registerMonitor("mem/physical/anonpages", "integer", printAnonpages, printAnonpagesInfo, sm);
 	registerMonitor("mem/swap/free", "integer", printSwapFree, printSwapFreeInfo, sm);
 	registerMonitor("mem/swap/used", "integer", printSwapUsed, printSwapUsedInfo, sm);
+
+	registerMonitor( "mem/physical/application", "integer", printAppl, printApplInfo, sm );
+	registerMonitor( "mem/physical/buf", "integer", printBuffers, printBuffersInfo, sm );
+	registerMonitor( "mem/physical/cached", "integer", printCached, printCachedInfo, sm );
 }
 
 void
@@ -93,7 +101,8 @@ updateMemory(void)
     
     len = sizeof(x);
     STotal = SUsed = SFree = -1;
-    Active = Inactive = Wired = Execpages = Filepages = MFree = Used = -1;
+    Active = Inactive = Wired = Execpages = Filepages = Anonpages = -1;
+    MFree = Used = -1;
     if (-1 < sysctl(mib, ARRLEN(mib), &x, &len, NULL, 0)) {
       STotal = (x.pagesize*x.swpages) >> 10;
       SUsed = (x.pagesize*x.swpginuse) >> 10;
@@ -104,7 +113,9 @@ updateMemory(void)
       Wired = (x.wired * x.pagesize) >> 10;
       Execpages = (x.execpages * x.pagesize) >> 10;
       Filepages = (x.filepages * x.pagesize) >> 10;
+      Anonpages = (x.anonpages * x.pagesize) >> 10;
       Used = Total - MFree;
+      Appl = Active - Filepages;
     }
   }
   return 0;
@@ -195,6 +206,18 @@ printFilepagesInfo(const char* cmd)
 }
 
 void
+printAnonpages(const char* cmd)
+{
+	fprintf(CurrentClient, "%d\n", Anonpages);
+}
+
+void
+printAnonpagesInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Anon Pages\t0\t%d\tKB\n", Total);
+}
+
+void
 printSwapUsed(const char* cmd)
 {
 	fprintf(CurrentClient, "%d\n", SUsed);
@@ -217,3 +240,40 @@ printSwapFreeInfo(const char* cmd)
 {
 	fprintf(CurrentClient, "Free Swap Memory\t0\t%d\tKB\n", STotal);
 }
+
+/* Linux compat */
+void
+printBuffers(const char* cmd)
+{
+	fprintf(CurrentClient, "%d\n", Filepages /* + bufmem */);
+}
+
+void
+printBuffersInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Buffer Memory\t0\t%d\tKB\n", Total);
+}
+
+void
+printCached(const char* cmd)
+{
+	fprintf(CurrentClient, "0\n");
+}
+
+void
+printCachedInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Cached Memory\t0\t%d\tKB\n", Total);
+}
+
+void
+printAppl(const char* cmd)
+{
+	fprintf(CurrentClient, "%d\n", Appl);
+}
+
+void
+printApplInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Application Memory\t0\t%d\tKB\n", Total);
+}
