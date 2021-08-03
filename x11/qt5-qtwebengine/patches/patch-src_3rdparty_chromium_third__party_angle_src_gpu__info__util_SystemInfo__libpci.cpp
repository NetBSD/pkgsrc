$NetBSD: patch-src_3rdparty_chromium_third__party_angle_src_gpu__info__util_SystemInfo__libpci.cpp,v 1.1 2021/08/03 21:04:35 markd Exp $

* Use pci.h from pkgsrc pciutils.

--- src/3rdparty/chromium/third_party/angle/src/gpu_info_util/SystemInfo_libpci.cpp.orig	2020-07-15 19:01:32.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/src/gpu_info_util/SystemInfo_libpci.cpp
@@ -9,7 +9,7 @@
 #include "gpu_info_util/SystemInfo_internal.h"
 
 #include <dlfcn.h>
-#include <pci/pci.h>
+#include <pciutils/pci.h>
 #include <unistd.h>
 
 #include "common/angleutils.h"
