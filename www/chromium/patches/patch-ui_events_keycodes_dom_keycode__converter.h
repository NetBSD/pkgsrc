$NetBSD: patch-ui_events_keycodes_dom_keycode__converter.h,v 1.24 2026/08/09 06:31:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/events/keycodes/dom/keycode_converter.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ ui/events/keycodes/dom/keycode_converter.h
@@ -65,7 +65,7 @@ class KeycodeConverter {
   // Convert a DomCode into a native keycode.
   static int DomCodeToNativeKeycode(DomCode code);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   // Convert a XKB keycode into a DomCode.
   static DomCode XkbKeycodeToDomCode(uint32_t xkb_keycode);
 
