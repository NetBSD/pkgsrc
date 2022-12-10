$NetBSD: patch-gfx_wgpu_wgpu-core_src_device_mod.rs,v 1.1 2022/12/10 09:25:58 abs Exp $

Fix build with rust 1.64.0 and its stricter borrow checker

--- gfx/wgpu/wgpu-core/src/device/mod.rs.orig	2022-08-15 18:04:39.000000000 +0000
+++ gfx/wgpu/wgpu-core/src/device/mod.rs
@@ -1486,6 +1486,7 @@ impl<B: GfxBackend> Device<B> {
 
         // `BTreeMap` has ordered bindings as keys, which allows us to coalesce
         // the descriptor writes into a single transaction.
+        let mut desc_set; // early declaration so it's dropped after write_map
         let mut write_map = BTreeMap::new();
         let mut used_buffer_ranges = Vec::new();
         for entry in desc.entries.iter() {
@@ -1779,7 +1780,7 @@ impl<B: GfxBackend> Device<B> {
             self.desc_allocator
                 .lock()
                 .allocate(&self.raw, &layout.raw, &layout.desc_count, 1)?;
-        let mut desc_set = desc_sets.pop().unwrap();
+        desc_set = desc_sets.pop().unwrap();
 
         // Set the descriptor set's label for easier debugging.
         if let Some(label) = desc.label.as_ref() {
