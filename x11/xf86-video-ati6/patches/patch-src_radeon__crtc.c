$NetBSD: patch-src_radeon__crtc.c,v 1.1 2013/10/31 00:07:24 wiz Exp $

--- src/radeon_crtc.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/radeon_crtc.c
@@ -170,7 +170,7 @@ RADEONComputePLL_old(RADEONPLLPtr pll,
 
     freq = freq * 1000;
 
-    ErrorF("freq: %lu\n", freq);
+/*    ErrorF("freq: %lu\n", freq); */
 
     if (flags & RADEON_PLL_USE_REF_DIV)
 	min_ref_div = max_ref_div = pll->reference_div;
@@ -300,11 +300,13 @@ RADEONComputePLL_old(RADEONPLLPtr pll,
 	}
     }
 
+/*
     ErrorF("best_freq: %u\n", (unsigned int)best_freq);
     ErrorF("best_feedback_div: %u\n", (unsigned int)best_feedback_div);
     ErrorF("best_frac_feedback_div: %u\n", (unsigned int)best_frac_feedback_div);
     ErrorF("best_ref_div: %u\n", (unsigned int)best_ref_div);
     ErrorF("best_post_div: %u\n", (unsigned int)best_post_div);
+*/
 
     if (best_freq == -1)
 	FatalError("Couldn't find valid PLL dividers\n");
@@ -438,11 +440,13 @@ RADEONComputePLL_new(RADEONPLLPtr pll,
     best_freq += pll->reference_freq * fb_div_frac;
     best_freq = best_freq / (ref_div * post_div);
 
+/*
     ErrorF("best_freq: %u\n", (unsigned int)best_freq);
     ErrorF("best_feedback_div: %u\n", (unsigned int)fb_div);
     ErrorF("best_frac_feedback_div: %u\n", (unsigned int)fb_div_frac);
     ErrorF("best_ref_div: %u\n", (unsigned int)ref_div);
     ErrorF("best_post_div: %u\n", (unsigned int)post_div);
+*/
 
 done:
     if (best_freq == 0)
