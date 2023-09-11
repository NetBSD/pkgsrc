$NetBSD: patch-third__party_wasm2c_src_prebuilt_wasm2c__source__includes.cc,v 1.1 2023/09/11 12:33:25 ryoon Exp $

--- third_party/wasm2c/src/prebuilt/wasm2c_source_includes.cc.orig	2023-05-25 21:19:41.000000000 +0000
+++ third_party/wasm2c/src/prebuilt/wasm2c_source_includes.cc
@@ -20,7 +20,7 @@ R"w2c_template(#include <malloc.h>
 )w2c_template"
 R"w2c_template(#define alloca _alloca
 )w2c_template"
-R"w2c_template(#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+R"w2c_template(#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 )w2c_template"
 R"w2c_template(#include <stdlib.h>
 )w2c_template"
