$NetBSD: patch-ext_r__analysis.c,v 1.2 2011/08/12 17:19:27 taca Exp $

* Switch to modern Ruby's API: http://cvs.pld-linux.org/

--- ext/r_analysis.c.orig	2011-08-08 00:44:55.000000000 +0000
+++ ext/r_analysis.c
@@ -1,6 +1,12 @@
+#include "lang.h"
+#ifdef RUBY18
 #include <regex.h>
-#include <locale.h>
 #include <st.h>
+#else
+#include <ruby/regex.h>
+#include <ruby/st.h>
+#endif
+#include <locale.h>
 #include "ferret.h"
 #include "analysis.h"
 
@@ -47,13 +53,15 @@ static ID id_token_stream;
 
 static VALUE object_space;
 
+#ifdef RUBY18
 extern int ruby_re_search(struct re_pattern_buffer *, const char *, int, int,
                           int, struct re_registers *);
+#endif
 
 int
 frt_rb_hash_size(VALUE hash)
 {
-    return RHASH(hash)->tbl->num_entries;
+    return RHASH_SIZE(hash);
 }
 
 /****************************************************************************
@@ -69,11 +77,11 @@ get_stopwords(VALUE rstop_words)
     int i, len;
     VALUE rstr;
     Check_Type(rstop_words, T_ARRAY);
-    len = RARRAY(rstop_words)->len;
-    stop_words = ALLOC_N(char *, RARRAY(rstop_words)->len + 1);
+    len = RARRAY_LEN(rstop_words);
+    stop_words = ALLOC_N(char *, RARRAY_LEN(rstop_words) + 1);
     stop_words[len] = NULL;
     for (i = 0; i < len; i++) {
-        rstr = rb_obj_as_string(RARRAY(rstop_words)->ptr[i]);
+        rstr = rb_obj_as_string(RARRAY_PTR(rstop_words)[i]);
         stop_words[i] = rs2s(rstr);
     }
     return stop_words;
@@ -132,7 +140,7 @@ frt_set_token(Token *tk, VALUE rt)
     if (rt == Qnil) return NULL;
 
     Data_Get_Struct(rt, RToken, rtk);
-    tk_set(tk, rs2s(rtk->text), RSTRING(rtk->text)->len,
+    tk_set(tk, rs2s(rtk->text), RSTRING_LEN(rtk->text),
            rtk->start, rtk->end, rtk->pos_inc);
     return tk;
 }
@@ -372,7 +380,7 @@ frt_token_to_s(VALUE self)
     RToken *token;
     char *buf;
     GET_TK(token, self);
-    buf = alloca(RSTRING(token->text)->len + 80);
+    buf = alloca(RSTRING_LEN(token->text) + 80);
     sprintf(buf, "token[\"%s\":%d:%d:%d]", rs2s(token->text),
             token->start, token->end, token->pos_inc);
     return rb_str_new2(buf);
@@ -621,7 +629,7 @@ typedef struct RegExpTokenStream {
     VALUE rtext;
     VALUE regex;
     VALUE proc;
-    int   curr_ind;  
+    long   curr_ind;  
 } RegExpTokenStream;
 
 static void
@@ -689,16 +697,20 @@ frt_rets_get_text(VALUE self)
     return RETS(ts)->rtext;
 }
 
+#ifdef RUBY18
+
 static Token *
 rets_next(TokenStream *ts)
 {
     static struct re_registers regs;
     int ret, beg, end;
-    struct RString *rtext = RSTRING(RETS(ts)->rtext);
+    struct RString *rtext = RSTRING_PTR(RETS(ts));
+    long rtext_len = RSTRING_LEN(RETS(ts)->rtext);
+    char *rtext_ptr = RSTRING_PTR(RETS(ts)->rtext);
     Check_Type(RETS(ts)->regex, T_REGEXP);
     ret = ruby_re_search(RREGEXP(RETS(ts)->regex)->ptr,
-                         rtext->ptr, rtext->len,
-                         RETS(ts)->curr_ind, rtext->len - RETS(ts)->curr_ind,
+			 rtext_ptr, rtext_len,
+			 RETS(ts)->curr_ind, rtext_len - RETS(ts)->curr_ind,
                          &regs);
 
     if (ret == -2) rb_raise(rb_eStandardError, "regexp buffer overflow");
@@ -707,16 +719,79 @@ rets_next(TokenStream *ts)
     beg = regs.beg[0];
     RETS(ts)->curr_ind = end = regs.end[0];
     if (NIL_P(RETS(ts)->proc)) {
-        return tk_set(&(CachedTS(ts)->token), rtext->ptr + beg, end - beg,
+        return tk_set(&(CachedTS(ts)->token), rtext_ptr + beg, end - beg,
                       beg, end, 1);
     } else {
-        VALUE rtok = rb_str_new(rtext->ptr + beg, end - beg);
+        VALUE rtok = rb_str_new(rtext_ptr + beg, end - beg);
         rtok = rb_funcall(RETS(ts)->proc, id_call, 1, rtok);
         return tk_set(&(CachedTS(ts)->token), rs2s(rtok),
-                      RSTRING(rtok)->len, beg, end, 1);
+                      RSTRING_LEN(rtok), beg, end, 1);
+    }
+}
+#else
+
+// partly lifted from ruby 1.9 string.c
+#include <ruby/encoding.h>
+#define BEG(no) regs->beg[no]
+#define END(no) regs->end[no]
+#define STR_ENC_GET(str) rb_enc_from_index(ENCODING_GET(str))
+static VALUE
+  scan_once(VALUE str, VALUE pat, long *start)
+{
+  VALUE match;
+  struct re_registers *regs;
+
+  if (rb_reg_search(pat, str, *start, 0) >= 0) {
+    match = rb_backref_get();
+    regs = RMATCH_REGS(match);
+    if (BEG(0) == END(0)) {
+      rb_encoding *enc = STR_ENC_GET(str);
+      /*
+      * Always consume at least one character of the input string
+       */
+        if (RSTRING_LEN(str) > END(0))
+        *start = END(0)+rb_enc_mbclen(RSTRING_PTR(str)+END(0),
+        RSTRING_END(str), enc);
+      else
+        *start = END(0)+1;
     }
+    else {
+      *start = END(0);
+    }
+    return rb_reg_nth_match(0, match);
+  }
+  return Qnil;
+}
+//
+
+static Token *
+  rets_next(TokenStream *ts)
+{
+  VALUE ret;
+  long rtok_len;
+  int beg, end;
+  Check_Type(RETS(ts)->regex, T_REGEXP);
+  ret = scan_once(RETS(ts)->rtext, RETS(ts)->regex, &(RETS(ts)->curr_ind));
+  if (NIL_P(ret)) return NULL;
+
+  Check_Type(ret, T_STRING);
+  rtok_len = RSTRING_LEN(ret);
+  beg = RETS(ts)->curr_ind - rtok_len;
+  end = RETS(ts)->curr_ind;
+
+  if (NIL_P(RETS(ts)->proc)) {
+    return tk_set(&(CachedTS(ts)->token), rs2s(ret), rtok_len,
+      beg, end, 1);
+  } else {
+    VALUE rtok;
+    rtok = rb_funcall(RETS(ts)->proc, id_call, 1, ret);
+    return tk_set(&(CachedTS(ts)->token), rs2s(rtok),
+      RSTRING_LEN(rtok), beg, end, 1);
+  }
 }
 
+#endif
+
 static TokenStream *
 rets_reset(TokenStream *ts, char *text)
 {
@@ -1029,8 +1104,8 @@ static int frt_add_mappings_i(VALUE key,
         }
         if (TYPE(key) == T_ARRAY) {
             int i;
-            for (i = RARRAY(key)->len - 1; i >= 0; i--) {
-                frt_add_mapping_i(mf, RARRAY(key)->ptr[i], to);
+            for (i = RARRAY_LEN(key) - 1; i >= 0; i--) {
+                frt_add_mapping_i(mf, RARRAY_PTR(key)[i], to);
             }
         }
         else {
