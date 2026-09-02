$NetBSD: patch-remoting_host_setup_me2me__native__messaging__host.cc,v 1.4 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/setup/me2me_native_messaging_host.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ remoting/host/setup/me2me_native_messaging_host.cc
@@ -331,7 +331,7 @@ void Me2MeNativeMessagingHost::ProcessSt
                                                   base::DictValue response) {
   DCHECK(task_runner()->BelongsToCurrentThread());
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // See: b/215406223, crbug.com/514525547
   // TODO: yuweih - consider re-enabling starting host via native messaging once
   // the GDM-managed host becomes the default.
