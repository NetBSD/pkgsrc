$NetBSD: patch-chrome_browser_memory__details.cc,v 1.23 2026/07/08 13:42:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/memory_details.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ chrome/browser/memory_details.cc
@@ -334,7 +334,7 @@ void MemoryDetails::CollectChildInfoOnUI
           });
     }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
     if (content::ZygoteHost::GetInstance()->IsZygotePid(process.pid)) {
       process.process_type = content::PROCESS_TYPE_ZYGOTE;
     }
