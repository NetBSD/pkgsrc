$NetBSD: patch-src_command.c,v 1.2 2021/07/19 13:03:39 tnn Exp $

Avoid integer overflow (CVE-2017-7483)
Avoid RCU (CVE-2021-33477, via https://bugs.gentoo.org/790782)

--- src/command.c.orig	2021-07-19 12:58:56.475014948 +0000
+++ src/command.c
@@ -207,7 +207,9 @@ void           rxvt_process_xwsh_seq    
 int            rxvt_privcases                (rxvt_t*, int, int, uint32_t);
 void           rxvt_process_terminal_mode    (rxvt_t*, int, int, int, unsigned int, const int*);
 void           rxvt_process_sgr_mode         (rxvt_t*, int, unsigned int, const int*);
+#if 0
 void           rxvt_process_graphics         (rxvt_t*, int);
+#endif
 void	       rxvt_process_getc	     (rxvt_t*, int, unsigned char);
 /*--------------------------------------------------------------------*
  *         END   `INTERNAL' ROUTINE PROTOTYPES                        *
@@ -5029,10 +5031,12 @@ rxvt_process_escape_seq(rxvt_t* r, int p
 	    rxvt_scr_add_lines(r, page, (const unsigned char *)"\n\r", 1, 2);
 	    break;
 
+#if 0
 	/* kidnapped escape sequence: Should be 8.3.48 */
 	case C1_ESA:	    /* ESC G */
 	    rxvt_process_graphics(r, page);
 	    break;
+#endif
 
 	/* 8.3.63: CHARACTER TABULATION SET */
 	case C1_HTS:	    /* ESC H */
@@ -5207,7 +5211,7 @@ rxvt_process_csi_seq(rxvt_t* r, int page
     i = ch - CSI_ICH;
     ndef = get_byte_array_bit(csi_defaults, i);
     for (p = 0; p < nargs; p++)
-	if (arg[p] == -1)
+	if (arg[p] < 0 || arg[p] > 30000)
 	    arg[p] = ndef;
 
 #ifdef DEBUG
@@ -6671,6 +6675,7 @@ rxvt_process_sgr_mode(rxvt_t* r, int pag
 }
 /*}}} */
 
+#if 0
 /*{{{ process Rob Nation's own graphics mode sequences */
 /* INTPROTO */
 void
@@ -6707,6 +6712,7 @@ rxvt_process_graphics(rxvt_t* r, int pag
 						     printable characters. */
 }
 /*}}} */
+#endif
 
 /* ------------------------------------------------------------------------- */
 
