$NetBSD: patch-remoting_host_setup_me2me__native__messaging__host.cc,v 1.3 2026/08/09 06:31:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/setup/me2me_native_messaging_host.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ remoting/host/setup/me2me_native_messaging_host.cc
@@ -331,7 +331,7 @@ void Me2MeNativeMessagingHost::ProcessSt
                                                   base::DictValue response) {
   DCHECK(task_runner()->BelongsToCurrentThread());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // See: b/215406223, crbug.com/514525547
   // TODO: yuweih - consider re-enabling starting host via native messaging once
   // the GDM-managed host becomes the default.
