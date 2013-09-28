$NetBSD: patch-mozilla_mfbt_Poison.cpp,v 1.1 2013/09/28 14:37:05 ryoon Exp $

--- mozilla/mfbt/Poison.cpp.orig	2013-09-16 18:26:51.000000000 +0000
+++ mozilla/mfbt/Poison.cpp
@@ -125,7 +125,11 @@ ReleaseRegion(void *region, uintptr_t si
 static bool
 ProbeRegion(uintptr_t region, uintptr_t size)
 {
+#if !defined(__sun__)
   if (madvise(reinterpret_cast<void*>(region), size, MADV_NORMAL)) {
+#else
+  if (posix_madvise(reinterpret_cast<void*>(region), size, MADV_NORMAL)) {
+#endif
     return true;
   } else {
     return false;
