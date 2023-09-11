$NetBSD: patch-toolkit_xre_glxtest.cpp,v 1.1 2023/09/11 12:33:25 ryoon Exp $

* Do not test Linux-specific entry for non-Linux.

--- toolkit/xre/glxtest/glxtest.cpp.orig	2023-05-25 21:19:41.000000000 +0000
+++ toolkit/xre/glxtest/glxtest.cpp
@@ -195,11 +195,15 @@ extern "C" {
 static void get_pci_status() {
   log("GLX_TEST: get_pci_status start\n");
 
+#if defined(__linux__)
   if (access("/sys/bus/pci/", F_OK) != 0 &&
       access("/sys/bus/pci_express/", F_OK) != 0) {
     record_warning("cannot access /sys/bus/pci");
     return;
   }
+#else
+  return;
+#endif
 
   void* libpci = dlopen("libpci.so.3", RTLD_LAZY);
   if (!libpci) {
