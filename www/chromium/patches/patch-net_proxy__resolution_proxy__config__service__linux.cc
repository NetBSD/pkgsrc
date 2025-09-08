$NetBSD: patch-net_proxy__resolution_proxy__config__service__linux.cc,v 1.6 2025/09/08 13:24:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/proxy_resolution/proxy_config_service_linux.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ net/proxy_resolution/proxy_config_service_linux.cc
@@ -11,7 +11,9 @@
 
 #include <errno.h>
 #include <limits.h>
+#if !BUILDFLAG(IS_BSD)
 #include <sys/inotify.h>
+#endif
 #include <unistd.h>
 
 #include <map>
@@ -502,6 +504,7 @@ bool SettingGetterImplGSettings::CheckVe
 }
 #endif  // defined(USE_GIO)
 
+#if !BUILDFLAG(IS_BSD)
 // Converts |value| from a decimal string to an int. If there was a failure
 // parsing, returns |default_value|.
 int StringToIntOrDefault(std::string_view value, int default_value) {
@@ -1039,6 +1042,7 @@ class SettingGetterImplKDE : public Prox
   // events on.
   scoped_refptr<base::SequencedTaskRunner> file_task_runner_;
 };
+#endif
 
 }  // namespace
 
@@ -1259,9 +1263,11 @@ ProxyConfigServiceLinux::Delegate::Deleg
     case base::nix::DESKTOP_ENVIRONMENT_KDE4:
     case base::nix::DESKTOP_ENVIRONMENT_KDE5:
     case base::nix::DESKTOP_ENVIRONMENT_KDE6:
+#if !BUILDFLAG(IS_BSD)
       setting_getter_ =
           std::make_unique<SettingGetterImplKDE>(env_var_getter_.get());
       break;
+#endif
     case base::nix::DESKTOP_ENVIRONMENT_XFCE:
     case base::nix::DESKTOP_ENVIRONMENT_LXQT:
     case base::nix::DESKTOP_ENVIRONMENT_OTHER:
