$NetBSD: patch-base_syslog__logging.cc,v 1.17 2026/04/10 17:31:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/syslog_logging.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ base/syslog_logging.cc
@@ -17,7 +17,7 @@
 #include "base/strings/string_util.h"
 #include "base/win/scoped_handle.h"
 #include "base/win/win_util.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // <syslog.h> defines LOG_INFO, LOG_WARNING macros that could conflict with
 // base::LOG_INFO, base::LOG_WARNING.
 #include <syslog.h>
@@ -151,7 +151,7 @@ EventLogMessage::~EventLogMessage() {
   if (user_sid != nullptr) {
     ::LocalFree(user_sid);
   }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const char kEventSource[] = "chrome";
   openlog(kEventSource, LOG_NOWAIT | LOG_PID, LOG_USER);
   // We can't use the defined names for the logging severity from syslog.h
