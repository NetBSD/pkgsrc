$NetBSD: patch-src_modules_cpu__frequency_bsd.cpp,v 1.2 2026/09/10 09:15:32 kikadf Exp $

* Add NetBSD support
https://github.com/Alexays/Waybar/pull/5318

--- src/modules/cpu_frequency/bsd.cpp.orig	2026-05-25 08:52:26.638052357 +0000
+++ src/modules/cpu_frequency/bsd.cpp
@@ -8,7 +8,7 @@ std::vector<float> waybar::modules::CpuF
   size_t len;
   int32_t freq;
 
-#ifndef __OpenBSD__
+#if defined(__FreeBSD__)
   char buffer[256];
   uint32_t i = 0;
   while (true) {
@@ -18,7 +18,11 @@ std::vector<float> waybar::modules::CpuF
     frequencies.push_back(freq);
     ++i;
   }
-#else
+#elif defined(__NetBSD__)
+  if (sysctlbyname("machdep.cpu.frequency.current", &freq, &len, NULL, 0) == 0) {
+    frequencies.push_back((float)freq);
+  }
+#elif defined(__OpenBSD__)
   int getMhz[] = {CTL_HW, HW_CPUSPEED};
   len = sizeof(freq);
   sysctl(getMhz, 2, &freq, &len, NULL, 0);
