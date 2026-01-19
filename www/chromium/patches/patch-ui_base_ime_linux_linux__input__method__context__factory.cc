$NetBSD: patch-ui_base_ime_linux_linux__input__method__context__factory.cc,v 1.14 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ime/linux/linux_input_method_context_factory.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/base/ime/linux/linux_input_method_context_factory.cc
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 #include "ui/base/ime/linux/fake_input_method_context.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_delegate.h"
 #endif
@@ -32,7 +32,7 @@ std::unique_ptr<LinuxInputMethodContext>
   if (auto factory = GetInputMethodContextFactoryForTest())
     return factory.Run(delegate);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Give the toolkit a chance to create the context.
   if (auto* linux_ui = LinuxUi::instance()) {
     if (auto context = linux_ui->CreateInputMethodContext(delegate))
