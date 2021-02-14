$NetBSD: patch-ext_q__boolean.c,v 1.1 2021/02/14 15:06:43 taca Exp $

Really compare two objects.

--- ext/q_boolean.c.orig	2021-01-11 06:15:38.573963936 +0000
+++ ext/q_boolean.c
@@ -1528,7 +1528,7 @@ static int  bq_eq(Query *self, Query *o)
     BooleanQuery *bq1 = BQ(self);
     BooleanQuery *bq2 = BQ(o);
     if ((bq1->coord_disabled != bq2->coord_disabled)
-        || (bq1->max_clause_cnt != bq1->max_clause_cnt)
+        || (bq1->max_clause_cnt != bq2->max_clause_cnt)
         || (bq1->clause_cnt != bq2->clause_cnt)) {
         return false;
     }
