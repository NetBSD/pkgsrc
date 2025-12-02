$NetBSD: patch-syncstorage-mysql_src_diesel__ext.rs,v 1.1 2025/12/02 22:28:59 wiz Exp $

Improve mariadb compatibility
https://github.com/felfert/syncstorage-rs-rpm/commit/c9311a47b89cb02c4a248e36d608571fe3097f9e

--- syncstorage-mysql/src/diesel_ext.rs.orig	2025-09-23 20:12:34.000000000 +0000
+++ syncstorage-mysql/src/diesel_ext.rs
@@ -3,11 +3,43 @@ use std::{fmt::Debug, marker::PhantomDat
 use diesel::{
     backend::Backend,
     insertable::CanInsertInSingleQuery,
+    mysql::Mysql,
     query_builder::{AstPass, InsertStatement, QueryFragment, QueryId},
+    query_dsl::methods::LockingDsl,
     result::QueryResult,
     Expression, QuerySource, RunQueryDsl,
 };
 
+/// Emit MySQL <= 5.7's `LOCK IN SHARE MODE`
+///
+/// MySQL 8 supports `FOR SHARE` as an alias (which diesel natively supports)
+pub trait LockInShareModeDsl {
+    type Output;
+
+    fn lock_in_share_mode(self) -> Self::Output;
+}
+
+impl<T> LockInShareModeDsl for T
+where
+    T: LockingDsl<LockInShareMode>,
+{
+    type Output = <T as LockingDsl<LockInShareMode>>::Output;
+
+    fn lock_in_share_mode(self) -> Self::Output {
+        self.with_lock(LockInShareMode)
+    }
+}
+
+#[derive(Debug, Clone, Copy, QueryId)]
+pub struct LockInShareMode;
+
+impl QueryFragment<Mysql> for LockInShareMode {
+    fn walk_ast<'b>(&'b self, mut out: AstPass<'_, 'b, Mysql>) -> QueryResult<()> {
+        out.push_sql(" LOCK IN SHARE MODE");
+        Ok(())
+    }
+}
+
 #[allow(dead_code)] // Not really dead, Rust can't see it.
 #[derive(Debug, Clone)]
 pub struct OnDuplicateKeyUpdate<T, U, Op, Ret, DB, X>(
