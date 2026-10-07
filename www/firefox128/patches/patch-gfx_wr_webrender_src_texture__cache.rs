$NetBSD: patch-gfx_wr_webrender_src_texture__cache.rs,v 1.1 2026/10/07 16:41:45 abs Exp $

Mark BudgetType related values as non pub to match firefox140.
Avoids build issue with webrender_ffi_generated.h defining
BudgetType_COUNT and then using COUNT

--- gfx/wr/webrender/src/texture_cache.rs.orig	2026-09-23 15:58:19.384304323 +0000
+++ gfx/wr/webrender/src/texture_cache.rs
@@ -272,9 +272,9 @@ enum BudgetType {
 }
 
 impl BudgetType {
-    pub const COUNT: usize = 7;
+    const COUNT: usize = 7;
 
-    pub const VALUES: [BudgetType; BudgetType::COUNT] = [
+    const VALUES: [BudgetType; BudgetType::COUNT] = [
         BudgetType::SharedColor8Linear,
         BudgetType::SharedColor8Nearest,
         BudgetType::SharedColor8Glyphs,
@@ -284,7 +284,7 @@ impl BudgetType {
         BudgetType::Standalone,
     ];
 
-    pub const PRESSURE_COUNTERS: [usize; BudgetType::COUNT] = [
+    const PRESSURE_COUNTERS: [usize; BudgetType::COUNT] = [
         profiler::ATLAS_COLOR8_LINEAR_PRESSURE,
         profiler::ATLAS_COLOR8_NEAREST_PRESSURE,
         profiler::ATLAS_COLOR8_GLYPHS_PRESSURE,
