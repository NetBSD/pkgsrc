$NetBSD: patch-src_3rdparty_chromium_third__party_harfbuzz-ng_src_src_hb-subset-cff1.cc,v 1.1 2023/04/12 19:24:06 adam Exp $

Remove unused variable.

--- src/3rdparty/chromium/third_party/harfbuzz-ng/src/src/hb-subset-cff1.cc.orig	2023-04-11 09:15:23.000000000 +0000
+++ src/3rdparty/chromium/third_party/harfbuzz-ng/src/src/hb-subset-cff1.cc
@@ -402,7 +402,7 @@ struct cff_subset_plan {
   void plan_subset_encoding (const OT::cff1::accelerator_subset_t &acc, hb_subset_plan_t *plan)
   {
     const Encoding *encoding = acc.encoding;
-    unsigned int  size0, size1, supp_size;
+    unsigned int  size0, size1;
     hb_codepoint_t  code, last_code = CFF_UNDEF_CODE;
     hb_vector_t<hb_codepoint_t> supp_codes;
 
@@ -412,7 +412,6 @@ struct cff_subset_plan {
       return;
     }
 
-    supp_size = 0;
     supp_codes.init ();
 
     subset_enc_num_codes = plan->num_output_glyphs () - 1;
@@ -448,7 +447,6 @@ struct cff_subset_plan {
 	  code_pair_t pair = { supp_codes[i], sid };
 	  subset_enc_supp_codes.push (pair);
 	}
-	supp_size += SuppEncoding::static_size * supp_codes.length;
       }
     }
     supp_codes.fini ();
