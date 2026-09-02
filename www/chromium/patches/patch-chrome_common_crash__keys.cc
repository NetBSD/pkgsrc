$NetBSD: patch-chrome_common_crash__keys.cc,v 1.25 2026/09/02 13:13:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/crash_keys.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/common/crash_keys.cc
@@ -56,7 +56,9 @@ class CrashKeyWithName {
   ~CrashKeyWithName() = delete;
 
   std::string_view Name() const { return name_; }
+#if BUILDFLAG(USE_CRASHPAD_ANNOTATION)
   std::string_view Value() const { return crash_key_.value(); }
+#endif
   void Clear() { crash_key_.Clear(); }
   void Set(std::string_view value) { crash_key_.Set(value); }
 
@@ -200,6 +202,7 @@ void AllocateCrashKeyInBrowserAndChildre
   GetCommandLineStringAnnotations().emplace_back(std::string(key)).Set(value);
 }
 
+#if BUILDFLAG(USE_CRASHPAD_ANNOTATION)
 void AppendStringAnnotationsCommandLineSwitch(base::CommandLine* command_line) {
   std::string string_annotations;
   for (const auto& crash_key : GetCommandLineStringAnnotations()) {
@@ -214,6 +217,7 @@ void AppendStringAnnotationsCommandLineS
   }
   command_line->AppendSwitchASCII(kStringAnnotationsSwitch, string_annotations);
 }
+#endif
 
 void SetCrashKeysFromCommandLine(const base::CommandLine& command_line) {
   SetStringAnnotations(command_line);
