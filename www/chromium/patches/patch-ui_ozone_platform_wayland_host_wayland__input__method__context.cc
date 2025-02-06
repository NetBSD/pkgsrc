$NetBSD: patch-ui_ozone_platform_wayland_host_wayland__input__method__context.cc,v 1.1 2025/02/06 09:58:34 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_input_method_context.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/platform/wayland/host/wayland_input_method_context.cc
@@ -60,7 +60,7 @@ namespace {
 // Only enable the preedit string for sequence mode (i.e. when using dead keys
 // or the Compose key) on Linux ozone/wayland (see b/220370007).
 constexpr CharacterComposer::PreeditStringMode kPreeditStringMode =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     CharacterComposer::PreeditStringMode::kAlwaysEnabled;
 #else
     CharacterComposer::PreeditStringMode::kHexModeOnly;
