$NetBSD: patch-config_makefiles_rust.mk,v 1.1 2022/07/21 23:56:39 nia Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

Use less memory to fix build under NetBSD/i386.
From: https://bugzilla.mozilla.org/show_bug.cgi?id=1644409

--- config/makefiles/rust.mk.orig	2022-06-08 14:10:19.000000000 +0000
+++ config/makefiles/rust.mk
@@ -58,6 +58,9 @@ ifdef MOZ_TSAN
 cargo_build_flags += -Zbuild-std=std,panic_abort
 RUSTFLAGS += -Zsanitizer=thread
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += -j1
+endif
 
 rustflags_sancov =
 ifdef LIBFUZZER
@@ -90,7 +93,8 @@ ifndef rustflags_sancov
 # Never enable when coverage is enabled to work around https://github.com/rust-lang/rust/issues/90045.
 ifndef MOZ_CODE_COVERAGE
 ifeq (,$(findstring gkrust_gtest,$(RUST_LIBRARY_FILE)))
-cargo_rustc_flags += -Clto
+cargo_rustc_flags += -Clto=thin
+export CARGO_PROFILE_RELEASE_LTO=thin
 endif
 # We need -Cembed-bitcode=yes for all crates when using -Clto.
 RUSTFLAGS += -Cembed-bitcode=yes
