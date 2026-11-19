$NetBSD: patch-ui_events_keycodes_dom_keycode__converter.h,v 1.33 2026/11/19 19:46:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/events/keycodes/dom/keycode_converter.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ ui/events/keycodes/dom/keycode_converter.h
@@ -65,7 +65,7 @@ class KeycodeConverter {
   // Convert a DomCode into a native keycode.
   static int DomCodeToNativeKeycode(DomCode code);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   // Convert a XKB keycode into a DomCode.
   static DomCode XkbKeycodeToDomCode(uint32_t xkb_keycode);
 
