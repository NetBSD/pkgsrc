$NetBSD: patch-config_makefiles_rust.mk,v 1.1 2020/08/07 09:09:48 maya Exp $

NetBSD<10 doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

Set -Cembed-bitcode=yes when using LTO to fix build with rust >= 1.45.
Upstream bug: https://bugzilla.mozilla.org/show_bug.cgi?id=1640982

--- config/makefiles/rust.mk.orig	2020-07-20 21:02:39.000000000 +0000
+++ config/makefiles/rust.mk
@@ -49,11 +49,19 @@ ifndef MOZ_DEBUG_RUST
 # Enable link-time optimization for release builds.
 cargo_rustc_flags += -C lto
 endif
+# Versions of rust >= 1.45 need -Cembed-bitcode=yes for all crates when
+# using -Clto.
+ifeq (,$(filter 1.38.% 1.39.% 1.40.% 1.41.% 1.42.% 1.43.% 1.44.%,$(RUSTC_VERSION)))
+RUSTFLAGS += -Cembed-bitcode=yes
+endif
 endif
 
 ifdef CARGO_INCREMENTAL
 export CARGO_INCREMENTAL
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += -j1
+endif
 
 rustflags_neon =
 ifeq (neon,$(MOZ_FPU))
