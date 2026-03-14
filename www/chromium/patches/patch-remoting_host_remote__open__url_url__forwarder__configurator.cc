$NetBSD: patch-remoting_host_remote__open__url_url__forwarder__configurator.cc,v 1.16 2026/03/14 12:40:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/remote_open_url/url_forwarder_configurator.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ remoting/host/remote_open_url/url_forwarder_configurator.cc
@@ -13,7 +13,7 @@ UrlForwarderConfigurator::UrlForwarderCo
 
 UrlForwarderConfigurator::~UrlForwarderConfigurator() = default;
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_WIN)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
 
 // static
 std::unique_ptr<UrlForwarderConfigurator> UrlForwarderConfigurator::Create() {
