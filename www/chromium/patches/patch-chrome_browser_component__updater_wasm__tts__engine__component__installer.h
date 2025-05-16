$NetBSD: patch-chrome_browser_component__updater_wasm__tts__engine__component__installer.h,v 1.1 2025/05/16 16:08:16 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/component_updater/wasm_tts_engine_component_installer.h.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/component_updater/wasm_tts_engine_component_installer.h
@@ -27,7 +27,7 @@ class WasmTtsEngineComponentInstallerPol
   WasmTtsEngineComponentInstallerPolicy& operator=(
       const WasmTtsEngineComponentInstallerPolicy&) = delete;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static std::string GetId();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
