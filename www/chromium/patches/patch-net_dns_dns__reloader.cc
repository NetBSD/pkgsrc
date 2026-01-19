$NetBSD: patch-net_dns_dns__reloader.cc,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/dns/dns_reloader.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ net/dns/dns_reloader.cc
@@ -10,6 +10,7 @@
 // - there's not guarantee it exists at all. :(
 #if BUILDFLAG(IS_POSIX)
 
+#include <netinet/in.h>
 #include <resolv.h>
 
 // This code only works on systems where the C library provides res_ninit(3) and
@@ -88,20 +89,37 @@ class DnsReloader : public NetworkChange
     if (!reload_state) {
       auto new_reload_state = std::make_unique<ReloadState>();
       new_reload_state->resolver_generation = resolver_generation_;
+#if BUILDFLAG(IS_NETBSD)
+      memset(&new_reload_state->res, 0, sizeof(new_reload_state->res));
+      res_ninit(&new_reload_state->res);
+#else
       res_ninit(&_res);
+#endif
       tls_reload_state_.Set(std::move(new_reload_state));
     } else if (reload_state->resolver_generation != resolver_generation_) {
       reload_state->resolver_generation = resolver_generation_;
       // It is safe to call res_nclose here since we know res_ninit will have
       // been called above.
+#if BUILDFLAG(IS_NETBSD)
+      res_nclose(&reload_state->res);
+      //memset(&reload_state->res, 0, sizeof(reload_state->res));
+      res_ninit(&reload_state->res);
+#else
       res_nclose(&_res);
       res_ninit(&_res);
+#endif
     }
   }
 
  private:
   struct ReloadState {
+#if BUILDFLAG(IS_NETBSD)
+    ~ReloadState() { res_nclose(&res); }
+
+    struct __res_state res;
+#else
     ~ReloadState() { res_nclose(&_res); }
+#endif
 
     int resolver_generation;
   };
