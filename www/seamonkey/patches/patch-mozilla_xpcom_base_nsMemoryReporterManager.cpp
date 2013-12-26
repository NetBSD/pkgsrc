$NetBSD: patch-mozilla_xpcom_base_nsMemoryReporterManager.cpp,v 1.1 2013/12/26 13:17:37 ryoon Exp $

--- mozilla/xpcom/base/nsMemoryReporterManager.cpp.orig	2013-12-11 04:29:24.000000000 +0000
+++ mozilla/xpcom/base/nsMemoryReporterManager.cpp
@@ -196,6 +196,43 @@ static nsresult GetResidentFast(int64_t*
     return GetResident(aN);
 }
 
+#ifdef __FreeBSD__
+#include <libutil.h>
+
+static nsresult
+GetKinfoVmentrySelf(int64_t* prss)
+{
+    int cnt;
+    struct kinfo_vmentry *vmmap, *kve;
+    if ((vmmap = kinfo_getvmmap(getpid(), &cnt)) == NULL)
+        return NS_ERROR_FAILURE;
+
+    if (prss)
+        *prss = 0;
+
+    for (int i = 0; i < cnt; i++) {
+        kve = &vmmap[i];
+        if (prss)
+            *prss += kve->kve_private_resident;
+    }
+
+    free(vmmap);
+    return NS_OK;
+}
+
+#define HAVE_PRIVATE_REPORTER
+static nsresult
+GetPrivate(int64_t* aN)
+{
+    int64_t priv;
+    nsresult rv = GetKinfoVmentrySelf(&priv);
+    if (NS_SUCCEEDED(rv))
+        *aN = priv * getpagesize();
+
+    return NS_OK;
+}
+#endif // FreeBSD
+
 #elif defined(SOLARIS)
 
 #include <procfs.h>
@@ -370,6 +407,24 @@ static nsresult GetResidentFast(int64_t*
 }
 
 #define HAVE_PRIVATE_REPORTER
+static nsresult
+GetPrivate(int64_t* aN)
+{
+    PROCESS_MEMORY_COUNTERS_EX pmcex;
+    pmcex.cb = sizeof(PROCESS_MEMORY_COUNTERS_EX);
+
+    if (!GetProcessMemoryInfo(
+            GetCurrentProcess(),
+            (PPROCESS_MEMORY_COUNTERS) &pmcex, sizeof(pmcex))) {
+        return NS_ERROR_FAILURE;
+    }
+
+    *aN = pmcex.PrivateUsage;
+    return NS_OK;
+}
+#endif  // XP_<PLATFORM>
+
+#ifdef HAVE_PRIVATE_REPORTER
 class PrivateReporter MOZ_FINAL : public MemoryUniReporter
 {
 public:
@@ -382,21 +437,10 @@ public:
 
     NS_IMETHOD GetAmount(int64_t* aAmount)
     {
-        PROCESS_MEMORY_COUNTERS_EX pmcex;
-        pmcex.cb = sizeof(PROCESS_MEMORY_COUNTERS_EX);
-
-        if (!GetProcessMemoryInfo(
-                GetCurrentProcess(),
-                (PPROCESS_MEMORY_COUNTERS) &pmcex, sizeof(pmcex))) {
-            return NS_ERROR_FAILURE;
-        }
-
-        *aAmount = pmcex.PrivateUsage;
-        return NS_OK;
+        return GetPrivate(aAmount);
     }
 };
-
-#endif  // XP_<PLATFORM>
+#endif
 
 #ifdef HAVE_VSIZE_AND_RESIDENT_REPORTERS
 class VsizeReporter MOZ_FINAL : public MemoryUniReporter
@@ -780,7 +824,7 @@ nsMemoryReporterManager::Init()
     RegisterReporter(new mozilla::dmd::DMDReporter);
 #endif
 
-#if defined(XP_LINUX)
+#if defined(XP_LINUX) || defined(__FreeBSD__)
     nsMemoryInfoDumper::Initialize();
 #endif
 
