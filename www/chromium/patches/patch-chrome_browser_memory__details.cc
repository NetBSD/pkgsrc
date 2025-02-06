$NetBSD: patch-chrome_browser_memory__details.cc,v 1.1 2025/02/06 09:57:49 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/memory_details.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/memory_details.cc
@@ -38,7 +38,7 @@
 #include "services/resource_coordinator/public/cpp/memory_instrumentation/memory_instrumentation.h"
 #include "ui/base/l10n/l10n_util.h"
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
 #include "content/public/browser/zygote_host/zygote_host_linux.h"
 #endif
 
@@ -335,7 +335,7 @@ void MemoryDetails::CollectChildInfoOnUI
           });
     }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
     if (content::ZygoteHost::GetInstance()->IsZygotePid(process.pid)) {
       process.process_type = content::PROCESS_TYPE_ZYGOTE;
     }
