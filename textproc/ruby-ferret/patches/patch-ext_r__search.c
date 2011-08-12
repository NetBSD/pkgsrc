$NetBSD: patch-ext_r__search.c,v 1.2 2011/08/12 17:19:27 taca Exp $

* Switch to modern Ruby's API: http://cvs.pld-linux.org/
* Care for incompatible rb_cvar_set() between ruby18 and ruby19.

--- ext/r_search.c.orig	2011-08-08 00:48:52.000000000 +0000
+++ ext/r_search.c
@@ -161,8 +161,7 @@ frt_get_td(TopDocs *td, VALUE rsearcher)
     VALUE hit_ary = rb_ary_new2(td->size);
 
     for (i = 0; i < td->size; i++) {
-        RARRAY(hit_ary)->ptr[i] = frt_get_hit(td->hits[i]);
-        RARRAY(hit_ary)->len++;
+	rb_ary_store(hit_ary, i, frt_get_hit(td->hits[i]));
     }
 
     rtop_docs = rb_struct_new(cTopDocs,
@@ -187,7 +186,7 @@ frt_td_to_s(int argc, VALUE *argv, VALUE
     int i;
     VALUE rhits = rb_funcall(self, id_hits, 0);
     Searcher *sea = (Searcher *)DATA_PTR(rb_funcall(self, id_searcher, 0));
-    const int len = RARRAY(rhits)->len;
+    const int len = RARRAY_LEN(rhits);
     char *str = ALLOC_N(char, len * 64 + 100);
     char *s = str;
     char *field = "id";
@@ -197,13 +196,13 @@ frt_td_to_s(int argc, VALUE *argv, VALUE
         field = frt_field(argv[0]);
     }
 
-    sprintf(s, "TopDocs: total_hits = %ld, max_score = %f [\n",
+    sprintf(s, "TopDocs: total_hits = %d, max_score = %f [\n",
             FIX2INT(rb_funcall(self, id_total_hits, 0)),
             NUM2DBL(rb_funcall(self, id_max_score, 0)));
     s += strlen(s);
 
     for (i = 0; i < len; i++) {
-        VALUE rhit = RARRAY(rhits)->ptr[i];
+        VALUE rhit = RARRAY_PTR(rhits)[i];
         int doc_id = FIX2INT(rb_funcall(rhit, id_doc, 0));
         char *value = "";
         LazyDoc *lzd = sea->get_lazy_doc(sea, doc_id);
@@ -280,7 +279,7 @@ frt_td_to_json(VALUE self)
 	VALUE rhit;
 	LazyDoc *lzd;
 	Searcher *sea = (Searcher *)DATA_PTR(rb_funcall(self, id_searcher, 0));
-	const int num_hits = RARRAY(rhits)->len;
+	const int num_hits = RARRAY_LEN(rhits);
 	int doc_id;
     int len = 32768;
 	char *str = ALLOC_N(char, len);
@@ -291,7 +290,7 @@ frt_td_to_json(VALUE self)
 	for (i = 0; i < num_hits; i++) {
         if (i) *(s++) = ',';
         *(s++) = '{';
-		rhit = RARRAY(rhits)->ptr[i];
+		rhit = RARRAY_PTR(rhits)[i];
 		doc_id = FIX2INT(rb_funcall(rhit, id_doc, 0));
 		lzd = sea->get_lazy_doc(sea, doc_id);
 		s = frt_lzd_load_to_json(lzd, &str, s, &len);
@@ -623,7 +622,11 @@ frt_mtq_set_dmt(VALUE self, VALUE rnum_t
         rb_raise(rb_eArgError,
                  "%d <= 0. @@max_terms must be > 0", max_terms);
     }
-    rb_cvar_set(cMultiTermQuery, id_default_max_terms, rnum_terms, Qfalse);
+    rb_cvar_set(cMultiTermQuery, id_default_max_terms, rnum_terms
+#ifdef RUBY18
+		, RTEST(ruby_verbose)
+#endif
+	    );
     return rnum_terms;
 }
 
@@ -1165,15 +1168,15 @@ frt_phq_add(int argc, VALUE *argv, VALUE
             {
                 int i;
                 char *t;
-                if (RARRAY(rterm)->len < 1) {
+                if (RARRAY_LEN(rterm) < 1) {
                     rb_raise(rb_eArgError, "Cannot add empty array to a "
                              "PhraseQuery. You must add either a string or "
                              "an array of strings");
                 }
-                t = StringValuePtr(RARRAY(rterm)->ptr[0]);
+                t = StringValuePtr(RARRAY_PTR(rterm)[0]);
                 phq_add_term(q, t, pos_inc);
-                for (i = 1; i < RARRAY(rterm)->len; i++) {
-                    t = StringValuePtr(RARRAY(rterm)->ptr[i]);
+                for (i = 1; i < RARRAY_LEN(rterm); i++) {
+                    t = StringValuePtr(RARRAY_PTR(rterm)[i]);
                     phq_append_multi_term(q, t);
                 }
                 break;
@@ -1426,7 +1429,11 @@ frt_fq_set_dms(VALUE self, VALUE val)
                  "%f < 0.0. :min_similarity must be > 0.0", min_sim);
     }
     qp_default_fuzzy_min_sim = (float)min_sim;
-    rb_cvar_set(cFuzzyQuery, id_default_min_similarity, val, Qfalse);
+    rb_cvar_set(cFuzzyQuery, id_default_min_similarity, val
+#ifdef RUBY18
+		, RTEST(ruby_verbose)
+#endif
+	    );
     return val;
 }
 
@@ -1458,7 +1465,11 @@ frt_fq_set_dpl(VALUE self, VALUE val)
                  "%d < 0. :prefix_length must be >= 0", pre_len);
     }
     qp_default_fuzzy_pre_len = pre_len;
-    rb_cvar_set(cFuzzyQuery, id_default_prefix_length, val, Qfalse);
+    rb_cvar_set(cFuzzyQuery, id_default_prefix_length, val
+#ifdef RUBY18
+		, RTEST(ruby_verbose)
+#endif
+	    );
     return val;
 }
 
@@ -1591,8 +1602,8 @@ frt_spanmtq_init(VALUE self, VALUE rfiel
 {
     Query *q = spanmtq_new(frt_field(rfield));
     int i;
-    for (i = RARRAY(rterms)->len - 1; i >= 0; i--) {
-        spanmtq_add_term(q, StringValuePtr(RARRAY(rterms)->ptr[i]));
+    for (i = RARRAY_LEN(rterms) - 1; i >= 0; i--) {
+        spanmtq_add_term(q, StringValuePtr(RARRAY_PTR(rterms)[i]));
     }
     Frt_Wrap_Struct(self, NULL, &frt_q_free, q);
     object_add(q, self);
@@ -1716,8 +1727,8 @@ frt_spannq_init(int argc, VALUE *argv, V
             int i;
             Query *clause;
             Check_Type(v, T_ARRAY);
-            for (i = 0; i < RARRAY(v)->len; i++) {
-                Data_Get_Struct(RARRAY(v)->ptr[i], Query, clause);
+            for (i = 0; i < RARRAY_LEN(v); i++) {
+                Data_Get_Struct(RARRAY_PTR(v)[i], Query, clause);
                 spannq_add_clause(q, clause);
             }
         }
@@ -1782,8 +1793,8 @@ frt_spanoq_init(int argc, VALUE *argv, V
         int i;
         Query *clause;
         Check_Type(rclauses, T_ARRAY);
-        for (i = 0; i < RARRAY(rclauses)->len; i++) {
-            Data_Get_Struct(RARRAY(rclauses)->ptr[i], Query, clause);
+        for (i = 0; i < RARRAY_LEN(rclauses); i++) {
+            Data_Get_Struct(RARRAY_PTR(rclauses)[i], Query, clause);
             spanoq_add_clause(q, clause);
         }
     }
@@ -2277,8 +2288,8 @@ frt_sort_init(int argc, VALUE *argv, VAL
         case 1: 
                 if (TYPE(rfields) == T_ARRAY) {
                     int i;
-                    for (i = 0; i < RARRAY(rfields)->len; i++) {
-                        frt_sort_add(sort, RARRAY(rfields)->ptr[i], reverse);
+                    for (i = 0; i < RARRAY_LEN(rfields); i++) {
+                        frt_sort_add(sort, RARRAY_PTR(rfields)[i], reverse);
                     }
                 } else {
                     frt_sort_add(sort, rfields, reverse);
@@ -2632,8 +2643,6 @@ frt_sea_search_each(int argc, VALUE *arg
 
     rb_scan_args(argc, argv, "11", &rquery, &roptions);
 
-    rb_thread_critical = Qtrue;
-
     Data_Get_Struct(rquery, Query, q);
     td = frt_sea_search_internal(q, roptions, sea);
 
@@ -2648,8 +2657,6 @@ frt_sea_search_each(int argc, VALUE *arg
     rtotal_hits = INT2FIX(td->total_hits);
     td_destroy(td);
 
-    rb_thread_critical = 0;
-
     return rtotal_hits;
 }
 
@@ -2753,8 +2760,7 @@ frt_sea_highlight(int argc, VALUE *argv,
         VALUE rexcerpts = rb_ary_new2(size);
 
         for (i = 0; i < size; i++) {
-            RARRAY(rexcerpts)->ptr[i] = rb_str_new2(excerpts[i]);
-            RARRAY(rexcerpts)->len++;
+	    rbary_store(rexcerpts, i, rb_str_new2(excerpts[i]));
         }
         ary_destroy(excerpts, &free);
         return rexcerpts;
@@ -2870,10 +2876,10 @@ frt_ms_init(int argc, VALUE *argv, VALUE
         rsearcher = argv[i];
         switch (TYPE(rsearcher)) {
             case T_ARRAY:
-                capa += RARRAY(rsearcher)->len;
+                capa += RARRAY_LEN(rsearcher);
                 REALLOC_N(searchers, Searcher *, capa);
-                for (j = 0; j < RARRAY(rsearcher)->len; j++) {
-                    VALUE rs = RARRAY(rsearcher)->ptr[j];
+                for (j = 0; j < RARRAY_LEN(rsearcher); j++) {
+                    VALUE rs = RARRAY_PTR(rsearcher)[j];
                     Data_Get_Struct(rs, Searcher, s);
                     searchers[top++] = s;
                 }
@@ -3107,7 +3113,11 @@ Init_MultiTermQuery(void)
     cMultiTermQuery = rb_define_class_under(mSearch, "MultiTermQuery", cQuery);
     rb_define_alloc_func(cMultiTermQuery, frt_data_alloc);
 
-    rb_cvar_set(cMultiTermQuery, id_default_max_terms, INT2FIX(512), Qfalse);
+    rb_cvar_set(cMultiTermQuery, id_default_max_terms, INT2FIX(512)
+#ifdef RUBY18
+		, RTEST(ruby_verbose)
+#endif
+	    );
     rb_define_singleton_method(cMultiTermQuery, "default_max_terms",
                                frt_mtq_get_dmt, 0);
     rb_define_singleton_method(cMultiTermQuery, "default_max_terms=",
@@ -3415,10 +3425,16 @@ Init_FuzzyQuery(void)
 
     cFuzzyQuery = rb_define_class_under(mSearch, "FuzzyQuery", cQuery);
     rb_define_alloc_func(cFuzzyQuery, frt_data_alloc);
-    rb_cvar_set(cFuzzyQuery, id_default_min_similarity,
-                rb_float_new(0.5), Qfalse);
-    rb_cvar_set(cFuzzyQuery, id_default_prefix_length,
-                INT2FIX(0), Qfalse);
+    rb_cvar_set(cFuzzyQuery, id_default_min_similarity, rb_float_new(0.5)
+#ifdef RUBY18
+		, RTEST(ruby_verbose)
+#endif
+	    );
+    rb_cvar_set(cFuzzyQuery, id_default_prefix_length, INT2FIX(0)
+#ifdef RUBY18
+		, RTEST(ruby_verbose)
+#endif
+	    );
 
     rb_define_singleton_method(cFuzzyQuery, "default_min_similarity",
                                frt_fq_get_dms, 0);
