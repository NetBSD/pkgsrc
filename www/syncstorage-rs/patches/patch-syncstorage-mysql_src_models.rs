$NetBSD: patch-syncstorage-mysql_src_models.rs,v 1.1 2025/12/02 22:28:59 wiz Exp $

Improve mariadb compatibility
https://github.com/felfert/syncstorage-rs-rpm/commit/c9311a47b89cb02c4a248e36d608571fe3097f9e

--- syncstorage-mysql/src/models.rs.orig	2025-09-23 20:12:34.000000000 +0000
+++ syncstorage-mysql/src/models.rs
@@ -24,6 +24,7 @@ use syncstorage_db_common::{
 use syncstorage_settings::{Quota, DEFAULT_MAX_TOTAL_RECORDS};
 
 use super::{
+    diesel_ext::LockInShareModeDsl,
     batch,
     error::DbError,
     pool::CollectionCache,
@@ -178,7 +179,7 @@ impl MysqlDb {
             .select(user_collections::modified)
             .filter(user_collections::user_id.eq(user_id))
             .filter(user_collections::collection_id.eq(collection_id))
-            .for_share()
+            .lock_in_share_mode()
             .first(&mut *self.conn.write()?)
             .optional()?;
         if let Some(modified) = modified {
