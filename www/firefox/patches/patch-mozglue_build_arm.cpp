$NetBSD: patch-mozglue_build_arm.cpp,v 1.2 2016/06/16 12:08:21 ryoon Exp $

* Support NetBSD/earm

--- mozglue/build/arm.cpp.orig	2015-09-29 21:45:02.000000000 +0000
+++ mozglue/build/arm.cpp
@@ -102,10 +102,13 @@ check_neon(void)
 }
 #    endif // !MOZILLA_PRESUME_NEON
 
-#  elif defined(__linux__) || defined(ANDROID)
+#  elif defined(__linux__) || defined(ANDROID) || defined(__NetBSD__)
 #    include <stdio.h>
 #    include <stdlib.h>
 #    include <string.h>
+#    if defined(__NetBSD__)
+#      include <sys/sysctl.h>
+#    endif
 
 enum{
   MOZILLA_HAS_EDSP_FLAG=1,
@@ -114,6 +117,29 @@ enum{
   MOZILLA_HAS_NEON_FLAG=8
 };
 
+#    if defined(__NetBSD__)
+static unsigned
+get_arm_cpu_flags(void)
+{
+  unsigned flags = 0;
+  size_t len;
+  int flag;
+
+  len = sizeof(flag);
+  if (sysctlbyname("machdep.simdex_present", &flag, &len, NULL, 0) == 0 && flag) {
+    flags |= MOZILLA_HAS_ARMV6_FLAG;
+    flags |= MOZILLA_HAS_EDSP_FLAG;
+  }
+
+  len = sizeof(flag);
+  if (sysctlbyname("machdep.neon_present", &flag, &len, NULL, 0) == 0 && flag) {
+    flags |= MOZILLA_HAS_ARMV7_FLAG;
+    flags |= MOZILLA_HAS_NEON_FLAG;
+  }
+
+  return flags;
+}
+#    else
 static unsigned
 get_arm_cpu_flags(void)
 {
@@ -178,6 +204,7 @@ get_arm_cpu_flags(void)
   }
   return flags;
 }
+#    endif
 
 // Cache a local copy so we only have to read /proc/cpuinfo once.
 static unsigned arm_cpu_flags = get_arm_cpu_flags();
