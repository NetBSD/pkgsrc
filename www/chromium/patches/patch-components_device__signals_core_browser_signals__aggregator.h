$NetBSD: patch-components_device__signals_core_browser_signals__aggregator.h,v 1.18 2026/04/21 15:21:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/browser/signals_aggregator.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/device_signals/core/browser/signals_aggregator.h
@@ -22,7 +22,7 @@ class SignalsAggregator : public KeyedSe
 
   ~SignalsAggregator() override = default;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Will asynchronously collect signals whose names are specified in the
   // `request` object, and will also use a `user_context` to validate that the
   // user has permissions to the device's signals. Invokes `callback` with the
