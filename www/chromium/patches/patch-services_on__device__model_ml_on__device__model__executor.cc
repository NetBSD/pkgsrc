$NetBSD: patch-services_on__device__model_ml_on__device__model__executor.cc,v 1.3 2025/12/11 09:13:43 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/on_device_model/ml/on_device_model_executor.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ services/on_device_model/ml/on_device_model_executor.cc
@@ -34,6 +34,7 @@
 #include "services/on_device_model/public/mojom/on_device_model.mojom.h"
 #include "services/on_device_model/public/mojom/on_device_model_service.mojom.h"
 
+// XXX PORT
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 #include "third_party/xnnpack/src/include/xnnpack.h"  // nogncheck
 #endif
