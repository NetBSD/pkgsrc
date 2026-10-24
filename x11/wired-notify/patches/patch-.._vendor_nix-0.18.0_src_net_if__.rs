$NetBSD: patch-.._vendor_nix-0.18.0_src_net_if__.rs,v 1.1 2026/10/24 17:24:13 pin Exp $

https://github.com/nix-rust/nix/pull/2709

--- ../vendor/nix-0.18.0/src/net/if_.rs.orig	2026-10-24 15:46:58.189897567 +0000
+++ ../vendor/nix-0.18.0/src/net/if_.rs
@@ -42,7 +42,6 @@ libc_bitflags!(
                   target_os = "ios",
                   target_os = "linux",
                   target_os = "macos",
-                  target_os = "netbsd",
                   target_os = "solaris"))]
         IFF_NOTRAILERS;
         /// Interface manages own routes.
