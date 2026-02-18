$NetBSD: patch-src_table.cc,v 1.1.2.2 2026/02/18 17:01:01 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- src/table.cc.orig	2025-01-18 10:51:30.000000000 +0000
+++ src/table.cc
@@ -51,7 +51,7 @@ void Html_tag_open_table(DilloHtml *html
    CssLength cssLength;
 
    if ((attrbuf = a_Html_get_attr(html, tag, tagsize, "border")))
-      border = isdigit(attrbuf[0]) ? strtol (attrbuf, NULL, 10) : 1;
+      border = dIsdigit(attrbuf[0]) ? strtol (attrbuf, NULL, 10) : 1;
    if ((attrbuf = a_Html_get_attr(html, tag, tagsize, "cellspacing"))) {
       cellspacing = strtol (attrbuf, NULL, 10);
       if (html->DocType == DT_HTML && html->DocTypeVersion >= 5.0f)
