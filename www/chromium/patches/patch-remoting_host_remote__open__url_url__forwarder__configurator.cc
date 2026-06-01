$NetBSD: patch-remoting_host_remote__open__url_url__forwarder__configurator.cc,v 1.20 2026/06/01 10:09:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/remote_open_url/url_forwarder_configurator.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ remoting/host/remote_open_url/url_forwarder_configurator.cc
@@ -13,7 +13,7 @@ UrlForwarderConfigurator::UrlForwarderCo
 
 UrlForwarderConfigurator::~UrlForwarderConfigurator() = default;
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_WIN)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
 
 // static
 std::unique_ptr<UrlForwarderConfigurator> UrlForwarderConfigurator::Create() {
