$NetBSD: patch-third__party_ipcz_src_standalone_base_logging.cc,v 1.5 2025/08/13 07:44:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/ipcz/src/standalone/base/logging.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ third_party/ipcz/src/standalone/base/logging.cc
@@ -55,6 +55,9 @@ LogMessage::LogMessage(const char* file,
 #elif BUILDFLAG(IS_ANDROID)
   stream_ << getpid() << ":" << gettid() << ":";
   const char* trimmed_file = strrchr(file, '/') + 1;
+#elif BUILDFLAG(IS_BSD)
+  stream_ << getpid() << ":" << pthread_self() << ":";
+  const char* trimmed_file = strrchr(file, '/') + 1;
 #elif BUILDFLAG(IS_WIN)
   const char* trimmed_file = file;
   stream_ << (::GetCurrentProcessId()) << ":" << ::GetCurrentThreadId() << ":";
