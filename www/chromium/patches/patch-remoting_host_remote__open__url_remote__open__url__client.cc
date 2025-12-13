$NetBSD: patch-remoting_host_remote__open__url_remote__open__url__client.cc,v 1.12 2025/12/13 14:54:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/remote_open_url/remote_open_url_client.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ remoting/host/remote_open_url/remote_open_url_client.cc
@@ -18,7 +18,7 @@
 #include "remoting/host/mojom/chromoting_host_services.mojom.h"
 #include "remoting/host/mojom/remote_url_opener.mojom.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/host/remote_open_url/remote_open_url_client_delegate_linux.h"
 #elif BUILDFLAG(IS_WIN)
 #include "remoting/host/remote_open_url/remote_open_url_client_delegate_win.h"
@@ -31,7 +31,7 @@ namespace {
 constexpr base::TimeDelta kRequestTimeout = base::Seconds(5);
 
 std::unique_ptr<RemoteOpenUrlClient::Delegate> CreateDelegate() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<RemoteOpenUrlClientDelegateLinux>();
 #elif BUILDFLAG(IS_WIN)
   return std::make_unique<RemoteOpenUrlClientDelegateWin>();
