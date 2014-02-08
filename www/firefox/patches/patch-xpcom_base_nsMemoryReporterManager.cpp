$NetBSD: patch-xpcom_base_nsMemoryReporterManager.cpp,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- xpcom/base/nsMemoryReporterManager.cpp.orig	2014-01-28 04:04:07.000000000 +0000
+++ xpcom/base/nsMemoryReporterManager.cpp
@@ -201,6 +201,43 @@ ResidentFastDistinguishedAmount(int64_t*
     return ResidentDistinguishedAmount(aN);
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
@@ -428,6 +465,24 @@ public:
 };
 
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
@@ -440,21 +495,10 @@ public:
 
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
@@ -842,7 +886,7 @@ nsMemoryReporterManager::Init()
     RegisterReporter(new mozilla::dmd::DMDReporter);
 #endif
 
-#if defined(XP_LINUX)
+#if defined(XP_LINUX) || defined(__FreeBSD__)
     nsMemoryInfoDumper::Initialize();
 #endif
 
