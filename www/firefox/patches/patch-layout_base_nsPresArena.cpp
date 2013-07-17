$NetBSD: patch-layout_base_nsPresArena.cpp,v 1.1 2013/07/17 11:00:13 jperkin Exp $

--- layout/base/nsPresArena.cpp.orig	2013-05-11 19:19:37.000000000 +0000
+++ layout/base/nsPresArena.cpp
@@ -144,7 +144,11 @@ ReleaseRegion(void *region, uintptr_t si
 static bool
 ProbeRegion(uintptr_t region, uintptr_t size)
 {
+#ifdef OS_SOLARIS
+  if (posix_madvise(reinterpret_cast<void*>(region), size, POSIX_MADV_NORMAL)) {
+#else
   if (madvise(reinterpret_cast<void*>(region), size, MADV_NORMAL)) {
+#endif
     return true;
   } else {
     return false;
