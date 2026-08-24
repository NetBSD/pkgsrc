$NetBSD: patch-src_factory.cpp,v 1.1 2026/08/24 14:25:32 kikadf Exp $

* Enable battery module on NetBSD

--- src/factory.cpp.orig	2026-05-24 09:08:08.278804792 +0000
+++ src/factory.cpp
@@ -46,7 +46,7 @@
 #include "modules/wayfire/window.hpp"
 #include "modules/wayfire/workspaces.hpp"
 #endif
-#if defined(__FreeBSD__) || defined(__linux__)
+#if defined(__FreeBSD__) || defined(__linux__) || defined(__NetBSD__)
 #include "modules/battery.hpp"
 #endif
 #if defined(HAVE_CPU_LINUX) || defined(HAVE_CPU_BSD)
@@ -129,7 +129,7 @@ waybar::AModule* waybar::Factory::makeMo
     auto hash_pos = name.find('#');
     auto ref = name.substr(0, hash_pos);
     auto id = hash_pos != std::string::npos ? name.substr(hash_pos + 1) : "";
-#if defined(__FreeBSD__) || defined(__linux__)
+#if defined(__FreeBSD__) || defined(__linux__) || defined(__NetBSD__)
     if (ref == "battery") {
       return new waybar::modules::Battery(id, bar_, config_[name]);
     }
