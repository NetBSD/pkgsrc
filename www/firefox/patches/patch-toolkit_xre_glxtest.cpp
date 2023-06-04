$NetBSD: patch-toolkit_xre_glxtest.cpp,v 1.6 2023/06/04 09:26:35 ryoon Exp $

* Do not test Linux-specific entry for non-Linux.

--- toolkit/xre/glxtest.cpp.orig	2023-04-14 16:28:10.000000000 +0000
+++ toolkit/xre/glxtest.cpp
@@ -289,11 +289,15 @@ static void close_logging() {
 #define PCI_BASE_CLASS_DISPLAY 0x03
 
 static void get_pci_status() {
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
