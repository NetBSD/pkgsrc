$NetBSD: patch-chrome_browser_component__updater_wasm__tts__engine__component__installer.cc,v 1.4 2025/08/13 07:44:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/component_updater/wasm_tts_engine_component_installer.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/component_updater/wasm_tts_engine_component_installer.cc
@@ -9,7 +9,7 @@
 #include "base/logging.h"
 #include "content/public/browser/browser_thread.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/accessibility/embedded_a11y_extension_loader.h"
 #include "chrome/common/extensions/extension_constants.h"
 #include "ui/accessibility/accessibility_features.h"
@@ -29,7 +29,7 @@ const base::FilePath::CharType kWorkletP
     FILE_PATH_LITERAL("streaming_worklet_processor.js");
 const base::FilePath::CharType kVoicesJsonFileName[] =
     FILE_PATH_LITERAL("voices.json");
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const base::FilePath::CharType kManifestV3FileName[] =
     FILE_PATH_LITERAL("wasm_tts_manifest_v3.json");
 const base::FilePath::CharType kOffscreenHtmlFileName[] =
@@ -49,7 +49,7 @@ constexpr std::array<uint8_t, 32> kWasmT
 
 const char kWasmTtsEngineManifestName[] = "WASM TTS Engine";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class WasmTTSEngineDirectory {
  public:
   static WasmTTSEngineDirectory* Get() {
@@ -119,7 +119,7 @@ void WasmTtsEngineComponentInstallerPoli
   VLOG(1) << "Component ready, version " << version.GetString() << " in "
           << install_dir.value();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (features::IsWasmTtsComponentUpdaterEnabled() &&
       !features::IsWasmTtsEngineAutoInstallDisabled()) {
     // Instead of installing the component extension as soon as it is ready,
@@ -137,7 +137,7 @@ void WasmTtsEngineComponentInstallerPoli
 bool WasmTtsEngineComponentInstallerPolicy::VerifyInstallation(
     const base::Value::Dict& /* manifest */,
     const base::FilePath& install_dir) const {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (features::IsWasmTtsComponentUpdaterV3Enabled()) {
     return base::PathExists(install_dir.Append(kManifestV3FileName)) &&
            base::PathExists(install_dir.Append(kBindingsMainWasmFileName)) &&
@@ -186,7 +186,7 @@ void RegisterWasmTtsEngineComponent(Comp
 
 void WasmTtsEngineComponentInstallerPolicy::GetWasmTTSEngineDirectory(
     base::OnceCallback<void(const base::FilePath&)> callback) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   WasmTTSEngineDirectory* wasm_directory = WasmTTSEngineDirectory::Get();
   wasm_directory->Get(std::move(callback));
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
