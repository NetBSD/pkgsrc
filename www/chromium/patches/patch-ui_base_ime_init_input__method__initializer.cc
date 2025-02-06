$NetBSD: patch-ui_base_ime_init_input__method__initializer.cc,v 1.1 2025/02/06 09:58:30 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ime/init/input_method_initializer.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/base/ime/init/input_method_initializer.cc
@@ -10,7 +10,7 @@
 #include "build/chromeos_buildflags.h"
 
 #if !BUILDFLAG(IS_CHROMEOS_ASH) && defined(USE_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #include "ui/base/ime/linux/fake_input_method_context.h"
 #include "ui/base/ime/linux/linux_input_method_context_factory.h"
 #elif BUILDFLAG(IS_WIN)
@@ -33,7 +33,7 @@ void ShutdownInputMethod() {
 }
 
 void InitializeInputMethodForTesting() {
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   GetInputMethodContextFactoryForTest() =
       base::BindRepeating([](LinuxInputMethodContextDelegate* delegate)
                               -> std::unique_ptr<LinuxInputMethodContext> {
@@ -46,7 +46,7 @@ void InitializeInputMethodForTesting() {
 
 void ShutdownInputMethodForTesting() {
 #if !BUILDFLAG(IS_CHROMEOS_ASH) && defined(USE_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   // The function owns the factory (as a static variable that's returned by
   // reference), so setting this to an empty factory will free the old one.
   GetInputMethodContextFactoryForTest() = LinuxInputMethodContextFactory();
