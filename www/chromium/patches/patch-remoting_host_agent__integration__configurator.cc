$NetBSD: patch-remoting_host_agent__integration__configurator.cc,v 1.1 2026/11/19 19:46:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/agent_integration_configurator.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ remoting/host/agent_integration_configurator.cc
@@ -16,7 +16,7 @@ AgentIntegrationConfigurator::AgentInteg
 
 AgentIntegrationConfigurator::~AgentIntegrationConfigurator() = default;
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 
 // static
 void AgentIntegrationConfigurator::IsSupported(IsSupportedCallback callback) {
