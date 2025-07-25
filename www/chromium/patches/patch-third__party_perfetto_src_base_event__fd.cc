$NetBSD: patch-third__party_perfetto_src_base_event__fd.cc,v 1.4 2025/07/25 16:17:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/perfetto/src/base/event_fd.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ third_party/perfetto/src/base/event_fd.cc
@@ -24,7 +24,8 @@
 #include <synchapi.h>
 #elif PERFETTO_BUILDFLAG(PERFETTO_OS_QNX)
 #include <unistd.h>
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+#elif (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 #include <sys/eventfd.h>
 #include <unistd.h>
@@ -59,7 +60,8 @@ void EventFd::Clear() {
     PERFETTO_DFATAL("EventFd::Clear()");
 }
 
-#elif PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) || \
+#elif (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX_BUT_NOT_QNX) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)) || \
     PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
 
 EventFd::EventFd() {
