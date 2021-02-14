$NetBSD: patch-ext_q__span.c,v 1.1 2021/02/14 15:06:43 taca Exp $

Really compare two objects.

--- ext/q_span.c.orig	2021-01-11 06:15:38.585794380 +0000
+++ ext/q_span.c
@@ -2254,7 +2254,7 @@ static int spanxq_eq(Query *self, Query 
 Query *spanxq_new_nr(Query *inc, Query *exc)
 {
     Query *self;
-    if (SpQ(inc)->field != SpQ(inc)->field) {
+    if (SpQ(inc)->field != SpQ(exc)->field) {
         RAISE(ARG_ERROR, "All clauses in a SpanQuery must have the same field. "
               "Attempted to add a SpanQuery with field \"%s\" along with a "
               "SpanQuery with field \"%s\" to an SpanNotQuery",
