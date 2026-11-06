$NetBSD: patch-src_modules_hyprland_language.cpp,v 1.1 2026/11/06 19:45:10 kikadf Exp $

* Use fmt::format instead of std::format

--- src/modules/hyprland/language.cpp.orig	2026-11-06 17:52:00.757920660 +0000
+++ src/modules/hyprland/language.cpp
@@ -188,7 +188,7 @@ void Language::initLanguage() {
   try {
     auto searcher = kbName.empty()
                         ? inputDevices
-                        : inputDevices.substr(inputDevices.find(std::format("\t{}\n", kbName)) +
+                        : inputDevices.substr(inputDevices.find(fmt::format("\t{}\n", kbName)) +
                                               kbName.length() + 2);
     searcher = searcher.substr(searcher.find("keymap:") + 8);
     searcher = searcher.substr(0, searcher.find_first_of("\n\t"));
