$NetBSD: patch-gfx_wr_swgl_build.rs,v 1.1 2022/07/21 23:56:39 nia Exp $

Work around an internal compiler error on i386 when optimization is enabled:

  cargo:warning=In file included from src/gl.cc:2637:0:
  cargo:warning=src/rasterize.h: In function 'void draw_quad_spans(int, Point2D*, uint32_t, glsl::Interpolants*, Texture&, Texture&, const ClipRect&) [with P = unsigned char]':
  cargo:warning=src/rasterize.h:782:20: internal compiler error: in convert_move, at expr.c:231
  cargo:warning= static inline void draw_quad_spans(int nump, Point2D p[4], uint32_t z,
  cargo:warning=                    ^~~~~~~~~~~~~~~


--- gfx/wr/swgl/build.rs.orig	2021-08-23 14:57:16.000000000 +0000
+++ gfx/wr/swgl/build.rs
@@ -196,6 +196,13 @@ fn main() {
         }
     }
 
+    // Work around a compiler bug
+    let target_triple = std::env::var("TARGET").expect("The TARGET environment variable must be set");
+    let target_name = target_triple.split('-').next().unwrap();
+    if ["i386", "i586", "i686"].contains(&target_name) { 
+        build.flag("-O0");
+    }
+
     build.file("src/gl.cc")
         .define("_GLIBCXX_USE_CXX11_ABI", Some("0"))
         .include(shader_dir)
