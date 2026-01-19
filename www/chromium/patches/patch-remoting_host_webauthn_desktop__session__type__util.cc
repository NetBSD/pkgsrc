$NetBSD: patch-remoting_host_webauthn_desktop__session__type__util.cc,v 1.12 2026/01/19 16:14:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/webauthn/desktop_session_type_util.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ remoting/host/webauthn/desktop_session_type_util.cc
@@ -11,7 +11,7 @@
 namespace remoting {
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DesktopSessionType GetDesktopSessionTypeInternal(
     std::unique_ptr<base::Environment> environment) {
   // Currently on Linux, a desktop session is either remote-only or local-only.
@@ -29,7 +29,7 @@ DesktopSessionType GetDesktopSessionType
 }  // namespace
 
 DesktopSessionType GetDesktopSessionType() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static const DesktopSessionType desktop_session_type =
       GetDesktopSessionTypeInternal(base::Environment::Create());
   return desktop_session_type;
