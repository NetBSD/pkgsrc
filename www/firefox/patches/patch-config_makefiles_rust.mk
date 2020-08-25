$NetBSD: patch-config_makefiles_rust.mk,v 1.3 2020/08/25 14:35:24 ryoon Exp $

--- config/makefiles/rust.mk.orig	2020-08-19 02:08:50.000000000 +0000
+++ config/makefiles/rust.mk
@@ -52,6 +52,9 @@ endif
 ifeq (1,$(MOZ_PARALLEL_BUILD))
 cargo_build_flags += -j1
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += -j1
+endif
 
 # These flags are passed via `cargo rustc` and only apply to the final rustc
 # invocation (i.e., only the top-level crate, not its dependencies).
@@ -68,6 +71,11 @@ endif
 ifeq (,$(filter 1.38.% 1.39.% 1.40.% 1.41.% 1.42.% 1.43.% 1.44.%,$(RUSTC_VERSION)))
 RUSTFLAGS += -Cembed-bitcode=yes
 endif
+# Versions of rust >= 1.45 need -Cembed-bitcode=yes for all crates when
+# using -Clto.
+ifeq (,$(filter 1.38.% 1.39.% 1.40.% 1.41.% 1.42.% 1.43.% 1.44.%,$(RUSTC_VERSION)))
+RUSTFLAGS += -Cembed-bitcode=yes
+endif
 endif
 endif
 
