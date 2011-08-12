$NetBSD: patch-ext_r__index.c,v 1.2 2011/08/12 17:19:27 taca Exp $

* Switch to modern Ruby's API: http://cvs.pld-linux.org/

--- ext/r_index.c.orig	2011-08-08 00:44:55.000000000 +0000
+++ ext/r_index.c
@@ -1,6 +1,10 @@
 #include "ferret.h"
 #include "index.h"
+#ifdef RUBY18
 #include <st.h>
+#else
+#include <ruby/st.h>
+#endif
 
 VALUE mIndex;
 
@@ -765,8 +769,8 @@ frt_te_each(VALUE self)
     char *term;
     int term_cnt = 0;
     VALUE vals = rb_ary_new2(2);
-    RARRAY(vals)->len = 2;
-    rb_mem_clear(RARRAY(vals)->ptr, 2);
+    rb_ary_store(vals, 0, Qnil);
+    rb_ary_store(vals, 1, Qnil);
 
 
     /* each is being called so there will be no current term */
@@ -775,8 +779,8 @@ frt_te_each(VALUE self)
     
     while (NULL != (term = te->next(te))) {
         term_cnt++;
-        RARRAY(vals)->ptr[0] = rb_str_new(term, te->curr_term_len);
-        RARRAY(vals)->ptr[1] = INT2FIX(te->curr_ti.doc_freq);
+        RARRAY_PTR(vals)[0] = rb_str_new(term, te->curr_term_len);
+        RARRAY_PTR(vals)[1] = INT2FIX(te->curr_ti.doc_freq);
         rb_yield(vals);
     }
     return INT2FIX(term_cnt);
@@ -1040,13 +1044,13 @@ frt_tde_each(VALUE self)
     int doc_cnt = 0;
     TermDocEnum *tde = (TermDocEnum *)DATA_PTR(self);
     VALUE vals = rb_ary_new2(2);
-    RARRAY(vals)->len = 2;
-    rb_mem_clear(RARRAY(vals)->ptr, 2);
+    rb_ary_store(vals, 0, Qnil);
+    rb_ary_store(vals, 1, Qnil);
 
     while (tde->next(tde)) {
         doc_cnt++;
-        RARRAY(vals)->ptr[0] = INT2FIX(tde->doc_num(tde));
-        RARRAY(vals)->ptr[1] = INT2FIX(tde->freq(tde));
+        RARRAY_PTR(vals)[0] = INT2FIX(tde->doc_num(tde));
+        RARRAY_PTR(vals)[1] = INT2FIX(tde->freq(tde));
         rb_yield(vals);
 
     }
@@ -1212,14 +1216,11 @@ frt_get_tv_term(TVTerm *tv_term)
     VALUE rpositions = Qnil;
     rtext = rb_str_new2(tv_term->text);
     if (tv_term->positions) {
-        VALUE *rpos;
         int *positions = tv_term->positions;
         rpositions = rb_ary_new2(freq);
-        rpos = RARRAY(rpositions)->ptr;
         for (i = 0; i < freq; i++) {
-            rpos[i] = INT2FIX(positions[i]);
+		rb_ary_store(rpositions, i, NT2FIX(positions[i]));
         }
-        RARRAY(rpositions)->len = freq;
     }
     return rb_struct_new(cTVTerm, rtext, rpositions, NULL);
 }
@@ -1237,25 +1238,20 @@ frt_get_tv(TermVector *tv)
     TVTerm *terms = tv->terms;
     const int t_cnt = tv->term_cnt;
     const int o_cnt = tv->offset_cnt;
-    VALUE rfield, rterms, *rts;
+    VALUE rfield, rterms;
     VALUE roffsets = Qnil;
     rfield = ID2SYM(rb_intern(tv->field));
 
     rterms = rb_ary_new2(t_cnt);
-    rts = RARRAY(rterms)->ptr;
     for (i = 0; i < t_cnt; i++) {
-        rts[i] = frt_get_tv_term(&terms[i]);
-        RARRAY(rterms)->len++;
+	rb_ary_store(rterms, i, frt_get_tv_term(&terms[i]));
     }
 
     if (tv->offsets) {
-        VALUE *ros;
         Offset *offsets = tv->offsets;
         roffsets = rb_ary_new2(o_cnt);
-        ros = RARRAY(roffsets)->ptr;
         for (i = 0; i < o_cnt; i++) {
-            ros[i] = frt_get_tv_offsets(&offsets[i]);
-            RARRAY(roffsets)->len++;
+	    rb_ary_store(roffsets, i, frt_get_tv_offsets(&offsets[i]));
         }
     }
 
@@ -1458,19 +1454,19 @@ frt_hash_to_doc_i(VALUE key, VALUE value
                 {
                     int i;
                     df->destroy_data = true;
-                    for (i = 0; i < RARRAY(value)->len; i++) {
-                        val = rb_obj_as_string(RARRAY(value)->ptr[i]);
-                        df_add_data_len(df, nstrdup(val), RSTRING(val)->len);
+                    for (i = 0; i < RARRAY_LEN(value); i++) {
+                        val = rb_obj_as_string(RARRAY_PTR(value)[i]);
+                        df_add_data_len(df, nstrdup(val), RSTRING_LEN(val));
                     }
                 }
                 break;
             case T_STRING:
-                df_add_data_len(df, rs2s(value), RSTRING(value)->len);
+                df_add_data_len(df, rs2s(value), RSTRING_LEN(value));
                 break;
             default:
                 val = rb_obj_as_string(value);
                 df->destroy_data = true;
-                df_add_data_len(df, nstrdup(val), RSTRING(val)->len);
+                df_add_data_len(df, nstrdup(val), RSTRING_LEN(val));
                 break;
         }
         doc_add_field(doc, df);
@@ -1498,9 +1494,9 @@ frt_get_doc(VALUE rdoc)
                 int i;
                 df = df_new("content");
                 df->destroy_data = true;
-                for (i = 0; i < RARRAY(rdoc)->len; i++) {
-                    val = rb_obj_as_string(RARRAY(rdoc)->ptr[i]);
-                    df_add_data_len(df, nstrdup(val), RSTRING(val)->len);
+                for (i = 0; i < RARRAY_LEN(rdoc); i++) {
+                    val = rb_obj_as_string(RARRAY_PTR(rdoc)[i]);
+                    df_add_data_len(df, nstrdup(val), RSTRING_LEN(val));
                 }
                 doc_add_field(doc, df);
             }
@@ -1511,13 +1507,13 @@ frt_get_doc(VALUE rdoc)
             break;
         case T_STRING:
             df = df_add_data_len(df_new("content"), rs2s(rdoc),
-                                 RSTRING(rdoc)->len);
+                                 RSTRING_LEN(rdoc));
             doc_add_field(doc, df);
             break;
         default:
             val = rb_obj_as_string(rdoc);
             df = df_add_data_len(df_new("content"), nstrdup(val),
-                                 RSTRING(val)->len);
+                                 RSTRING_LEN(val));
             df->destroy_data = true;
             doc_add_field(doc, df);
             break;
@@ -1597,14 +1593,14 @@ frt_iw_add_readers(VALUE self, VALUE rre
     IndexReader **irs;
     Check_Type(rreaders, T_ARRAY);
 
-    irs = ALLOC_N(IndexReader *, RARRAY(rreaders)->len);
-    i = RARRAY(rreaders)->len;
+    irs = ALLOC_N(IndexReader *, RARRAY_LEN(rreaders));
+    i = RARRAY_LEN(rreaders);
     while (i-- > 0) {
         IndexReader *ir;
-        Data_Get_Struct(RARRAY(rreaders)->ptr[i], IndexReader, ir);
+        Data_Get_Struct(RARRAY_PTR(rreaders)[i], IndexReader, ir);
         irs[i] = ir;
     }
-    iw_add_readers(iw, irs, RARRAY(rreaders)->len);
+    iw_add_readers(iw, irs, RARRAY_LEN(rreaders));
     free(irs);
     return self;
 }
@@ -1953,9 +1949,7 @@ frt_lazy_df_load(VALUE self, VALUE rkey,
             rdata = rb_ary_new2(lazy_df->size);
             for (i = 0; i < lazy_df->size; i++) {
                 char *data = lazy_df_get_data(lazy_df, i);
-                RARRAY(rdata)->ptr[i] =
-                    rb_str_new(data, lazy_df->data[i].length);
-                RARRAY(rdata)->len++;
+		rb_ary_store(rdata, i, rb_str_new(data, lazy_df->data[i].length));
             }
         }
         rb_hash_aset(self, rkey, rdata);
@@ -2038,8 +2032,7 @@ frt_get_lazy_doc(LazyDoc *lazy_doc)
     rb_ivar_set(self, id_data, rdata);
 
     for (i = 0; i < lazy_doc->size; i++) {
-        RARRAY(rfields)->ptr[i] = ID2SYM(rb_intern(lazy_doc->fields[i]->name));
-        RARRAY(rfields)->len++;
+	rb_ary_store(rfields, i, ID2SYM(rb_intern(lazy_doc->fields[i]->name)));
     }
     rb_ivar_set(self, id_fields, rfields);
 
@@ -2115,11 +2108,11 @@ frt_ir_init(VALUE self, VALUE rdir)
 
     if (TYPE(rdir) == T_ARRAY) {
         VALUE rdirs = rdir;
-        const int reader_cnt = RARRAY(rdir)->len;
+        const int reader_cnt = RARRAY_LEN(rdir);
         IndexReader **sub_readers = ALLOC_N(IndexReader *, reader_cnt);
         int i;
         for (i = 0; i < reader_cnt; i++) {
-            rdir = RARRAY(rdirs)->ptr[i];
+            rdir = RARRAY_PTR(rdirs)[i];
             switch (TYPE(rdir)) {
                 case T_DATA:
                     if (CLASS_OF(rdir) == cIndexReader) {
@@ -2235,11 +2228,11 @@ frt_ir_get_norms_into(VALUE self, VALUE 
     int offset;
     offset = FIX2INT(roffset);
     Check_Type(rnorms, T_STRING);
-    if (RSTRING(rnorms)->len < offset + ir->max_doc(ir)) {
-        rb_raise(rb_eArgError, "supplied a string of length:%d to "
+    if (RSTRING_LEN(rnorms) < offset + ir->max_doc(ir)) {
+        rb_raise(rb_eArgError, "supplied a string of length:%ld to "
                  "IndexReader#get_norms_into but needed a string of length "
                  "offset:%d + maxdoc:%d",
-                 RSTRING(rnorms)->len, offset, ir->max_doc(ir));
+                 RSTRING_LEN(rnorms), offset, ir->max_doc(ir));
     }
 
     ir_get_norms_into(ir, frt_field(rfield),
@@ -2382,8 +2375,7 @@ frt_get_doc_range(IndexReader *ir, int p
     len = max - pos;
     ary = rb_ary_new2(len);
     for (i = 0; i < len; i++) {
-        RARRAY(ary)->ptr[i] = frt_get_lazy_doc(ir->get_lazy_doc(ir, i + pos));
-        RARRAY(ary)->len++;
+	rb_ary_store(ary, i, frt_get_lazy_doc(ir->get_lazy_doc(ir, i + pos)));
     }
     return ary;
 }
@@ -2410,9 +2402,8 @@ frt_ir_get_doc(int argc, VALUE *argv, VA
             pos = FIX2INT(arg1);
             pos = (pos < 0) ? (max + pos) : pos;
             if (pos < 0 || pos >= max) {
-                rb_raise(rb_eArgError, ":%d is out of range [%d..%d] for "
-                         "IndexReader#[]", pos, 0, max,
-                         rb_id2name(SYM2ID(argv)));
+                rb_raise(rb_eArgError, ":%ld is out of range [%d..%ld] for "
+                         "IndexReader#[]", pos, 0, max);
             }
             return frt_get_lazy_doc(ir->get_lazy_doc(ir, pos));
         }
