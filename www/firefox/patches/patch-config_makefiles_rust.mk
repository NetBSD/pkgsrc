$NetBSD: patch-config_makefiles_rust.mk,v 1.9 2021/12/11 14:10:01 ryoon Exp $

NetBSD doesn't get along with parallel rust builds (it causes issues
with ld.so) which are the default. Force -j1.

--- config/makefiles/rust.mk.orig	2021-11-25 21:18:06.000000000 +0000
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
