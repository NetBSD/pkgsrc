$NetBSD: patch-.._vendor_criner-0.4.1_src_engine_stage_report_git.rs,v 1.1 2026/08/30 08:11:25 he Exp $

Convert ot using portable-atomic for 32-bit CPU support.

--- ../vendor/criner-0.4.1/src/engine/stage/report/git.rs.orig	2026-08-29 13:47:01.465125370 +0000
+++ ../vendor/criner-0.4.1/src/engine/stage/report/git.rs
@@ -6,9 +6,10 @@ use crate::{
 use futures_util::{FutureExt, future::BoxFuture};
 use std::{
     path::{Path, PathBuf},
-    sync::atomic::{AtomicU64, Ordering},
+//    sync::atomic::{AtomicU64, Ordering},
     time::{SystemTime, UNIX_EPOCH},
 };
+use portable_atomic::{AtomicU64, Ordering};
 
 static TOTAL_LOOSE_OBJECTS_WRITTEN: AtomicU64 = AtomicU64::new(0);
 
