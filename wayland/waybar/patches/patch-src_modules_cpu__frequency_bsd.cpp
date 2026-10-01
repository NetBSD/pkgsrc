$NetBSD: patch-src_modules_cpu__frequency_bsd.cpp,v 1.3 2026/10/01 12:17:16 kikadf Exp $

* Add NetBSD support
https://github.com/Alexays/Waybar/pull/5318

--- src/modules/cpu_frequency/bsd.cpp.orig	2026-02-06 20:15:03.000000000 +0000
+++ src/modules/cpu_frequency/bsd.cpp
@@ -8,21 +8,58 @@ std::vector<float> waybar::modules::CpuF
   size_t len;
   int32_t freq;
 
-#ifndef __OpenBSD__
+#if defined(__NetBSD__)
   char buffer[256];
+  const char *freq_sysctls[] = {
+#if defined(__powerpc__)
+    "machdep.intrepid.frequency.current",
+#endif
+#if defined(__mips__)
+    "machdep.loongson.frequency.current",
+#endif
+#if defined(__i386__) || defined(__x86_64__)
+    "machdep.est.frequency.current",
+    "machdep.powernow.frequency.current",
+#endif
+    "machdep.cpu.frequency.current",
+    "machdep.frequency.current",
+    NULL
+  };
   uint32_t i = 0;
+
   while (true) {
-    len = 4;
-    snprintf(buffer, 256, "dev.cpu.%u.freq", i);
+    len = sizeof(freq);
+    snprintf(buffer, 256, "machdep.cpufreq.cpu%u.current", i);
     if (sysctlbyname(buffer, &freq, &len, NULL, 0) == -1 || len <= 0) break;
-    frequencies.push_back(freq);
+    frequencies.push_back((float)freq);
     ++i;
-  }
-#else
+  } 
+
+  if (frequencies.empty()) {
+    const char **s;
+    for (s = freq_sysctls; *s != NULL; ++s) {
+      len = sizeof(freq);
+      if (sysctlbyname(*s, &freq, &len, NULL, 0) != -1 || len <= 0) {
+        frequencies.push_back((float)freq);
+        break;
+      }
+    }
+  } 
+#elif defined(__OpenBSD__)
   int getMhz[] = {CTL_HW, HW_CPUSPEED};
   len = sizeof(freq);
   sysctl(getMhz, 2, &freq, &len, NULL, 0);
   frequencies.push_back((float)freq);
+#else
+  char buffer[256];
+  uint32_t i = 0;
+  while (true) {
+    len = 4;
+    snprintf(buffer, 256, "dev.cpu.%u.freq", i);
+    if (sysctlbyname(buffer, &freq, &len, NULL, 0) == -1 || len <= 0) break;
+    frequencies.push_back(freq);
+    ++i;
+  }
 #endif
 
   if (frequencies.empty()) {
