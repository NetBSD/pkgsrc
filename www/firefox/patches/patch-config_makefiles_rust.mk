$NetBSD: patch-config_makefiles_rust.mk,v 1.2 2020/08/07 08:29:42 maya Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

Set -Cembed-bitcode=yes when using LTO to fix build with rust >= 1.45.
Upstream bug: https://bugzilla.mozilla.org/show_bug.cgi?id=1640982

--- config/makefiles/rust.mk.orig	2020-04-03 19:34:34.000000000 +0000
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
@@ -62,6 +65,11 @@ ifndef MOZ_DEBUG_RUST
 # gkrust_gtest.
 ifeq (,$(findstring gkrust_gtest,$(RUST_LIBRARY_FILE)))
 cargo_rustc_flags += -Clto
+endif
+# Versions of rust >= 1.45 need -Cembed-bitcode=yes for all crates when
+# using -Clto.
+ifeq (,$(filter 1.38.% 1.39.% 1.40.% 1.41.% 1.42.% 1.43.% 1.44.%,$(RUSTC_VERSION)))
+RUSTFLAGS += -Cembed-bitcode=yes
 endif
 endif
 endif
