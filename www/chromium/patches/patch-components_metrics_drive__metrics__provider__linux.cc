$NetBSD: patch-components_metrics_drive__metrics__provider__linux.cc,v 1.1 2025/02/06 09:58:00 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/metrics/drive_metrics_provider_linux.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/metrics/drive_metrics_provider_linux.cc
@@ -4,7 +4,13 @@
 
 #include "components/metrics/drive_metrics_provider.h"
 
+#if BUILDFLAG(IS_BSD)
+#include <sys/types.h>
+#define MAJOR(dev) major(dev)
+#define MINOR(dev) minor(dev)
+#else
 #include <linux/kdev_t.h>  // For MAJOR()/MINOR().
+#endif
 #include <sys/stat.h>
 #include <string>
 
