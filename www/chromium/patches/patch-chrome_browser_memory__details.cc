$NetBSD: patch-chrome_browser_memory__details.cc,v 1.27 2026/09/29 07:42:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/memory_details.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/memory_details.cc
@@ -335,7 +335,7 @@ void MemoryDetails::CollectChildInfoOnUI
           });
     }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
     if (content::ZygoteHost::GetInstance()->IsZygotePid(process.pid)) {
       process.process_type = content::PROCESS_TYPE_ZYGOTE;
     }
