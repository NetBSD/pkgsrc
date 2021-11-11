$NetBSD: patch-config_makefiles_rust.mk,v 1.8 2021/11/11 16:48:04 ryoon Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

--- config/makefiles/rust.mk.orig	2021-10-28 18:58:50.000000000 +0000
+++ config/makefiles/rust.mk
@@ -58,6 +58,9 @@ ifdef MOZ_TSAN
 cargo_build_flags += -Zbuild-std=std,panic_abort
 RUSTFLAGS += -Zsanitizer=thread
 endif
+ifeq ($(OS_ARCH),NetBSD)
+cargo_build_flags += -j1
+endif
 
 # These flags are passed via `cargo rustc` and only apply to the final rustc
 # invocation (i.e., only the top-level crate, not its dependencies).
