$NetBSD: patch-config_makefiles_rust.mk,v 1.2 2020/08/29 18:39:34 nia Exp $

NetBSD<10 doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

--- config/makefiles/rust.mk.orig	2020-08-17 18:26:21.000000000 +0000
+++ config/makefiles/rust.mk
@@ -60,6 +60,10 @@ ifdef CARGO_INCREMENTAL
 export CARGO_INCREMENTAL
 endif
 
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += -j1
+endif
+
 rustflags_neon =
 ifeq (neon,$(MOZ_FPU))
 # Enable neon and disable restriction to 16 FPU registers
