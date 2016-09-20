$NetBSD: patch-mozglue_build_arm.cpp,v 1.3 2016/09/20 20:01:41 ryoon Exp $

* Support NetBSD/earm

--- mozglue/build/arm.cpp.orig	2016-08-01 16:14:43.000000000 +0000
+++ mozglue/build/arm.cpp
@@ -13,10 +13,13 @@
 // we don't compile one of these detection methods. The detection code here is
 // based on the CPU detection in libtheora.
 
-#  if defined(__linux__) || defined(ANDROID)
+#  if defined(__linux__) || defined(ANDROID) || defined(__NetBSD__)
 #    include <stdio.h>
 #    include <stdlib.h>
 #    include <string.h>
+#    if defined(__NetBSD__)
+#      include <sys/sysctl.h>
+#    endif
 
 enum{
   MOZILLA_HAS_EDSP_FLAG=1,
@@ -25,6 +28,29 @@ enum{
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
@@ -89,6 +115,7 @@ get_arm_cpu_flags(void)
   }
   return flags;
 }
+#    endif
 
 // Cache a local copy so we only have to read /proc/cpuinfo once.
 static unsigned arm_cpu_flags = get_arm_cpu_flags();
