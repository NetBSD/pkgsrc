$NetBSD: patch-src_html.cc,v 1.1.2.2 2026/02/18 17:01:00 maya Exp $

Avoid ctype(3) abuses

Valid argument of ctype(3) functions must be either EOF or non-negative
value within the range representable as unsigned char.  Invalid values
leads to undefined behavior.

Add all missing d*() ctype(3) helper functions and switch to use them.

Noticed by running dillo on NetBSD where dillo crashes due such
abuses.

See: https://lists.mailman3.com/hyperkitty/list/dillo-dev@mailman3.com/thread/L6QLXSD6UBDK3M5CMXQMRWD6ZB4C65MR/

--- src/html.cc.orig	2025-01-18 10:51:30.000000000 +0000
+++ src/html.cc
@@ -17,7 +17,6 @@
 /*-----------------------------------------------------------------------------
  * Includes
  *---------------------------------------------------------------------------*/
-#include <ctype.h>      /* for isspace */
 #include <string.h>     /* for memcpy and memmove */
 #include <stdlib.h>
 #include <stdio.h>      /* for sprintf */
@@ -883,7 +882,7 @@ static const char *Html_parse_numeric_ch
    errno = 0;
 
    if (*s == 'x' || *s == 'X') {
-      if (isxdigit(*++s)) {
+      if (dIsxdigit(*++s)) {
          /* strtol with base 16 accepts leading "0x" - we don't */
          if (*s == '0' && s[1] == 'x') {
             s++;
@@ -892,7 +891,7 @@ static const char *Html_parse_numeric_ch
             codepoint = strtol(s, &s, 16);
          }
       }
-   } else if (isdigit(*s)) {
+   } else if (dIsdigit(*s)) {
       codepoint = strtol(s, &s, 10);
    }
    if (errno)
@@ -984,7 +983,7 @@ static const char *Html_parse_named_char
    char *s = tok;
    const char *ret = NULL;
 
-   while (*++s && (isalnum(*s) || strchr(":_.-", *s))) ;
+   while (*++s && (dIsalnum(*s) || strchr(":_.-", *s))) ;
    c = *s;
    *s = '\0';
    if (c != ';') {
@@ -1051,7 +1050,7 @@ static const char *Html_parse_entity(Dil
 
    if (*tok == '#') {
       ret = Html_parse_numeric_charref(html, tok+1, is_attr, entsize);
-   } else if (isalpha(*tok)) {
+   } else if (dIsalpha(*tok)) {
       ret = Html_parse_named_charref(html, tok, is_attr, entsize);
    } else if (prefs.show_extra_warnings &&
        (!(html->DocType == DT_HTML && html->DocTypeVersion >= 5.0f))) {
@@ -1249,11 +1248,11 @@ static void Html_process_word(DilloHtml 
       /* all this overhead is to catch white-space entities */
       Pword = a_Html_parse_entities(html, word, size);
       for (start = i = 0; Pword[i]; start = i)
-         if (isspace(Pword[i])) {
-            while (Pword[++i] && isspace(Pword[i])) ;
+         if (dIsspace(Pword[i])) {
+            while (Pword[++i] && dIsspace(Pword[i])) ;
             Html_process_space(html, Pword + start, i - start);
          } else {
-            while (Pword[++i] && !isspace(Pword[i])) ;
+            while (Pword[++i] && !dIsspace(Pword[i])) ;
             HT2TB(html)->addText(Pword + start, i - start, html->wordStyle ());
             html->pre_column += i - start;
             html->PreFirstChar = false;
@@ -1287,8 +1286,8 @@ static void Html_process_word(DilloHtml 
       for (start = i = 0; word2[i]; start = i) {
          int len;
 
-         if (isspace(word2[i])) {
-            while (word2[++i] && isspace(word2[i])) ;
+         if (dIsspace(word2[i])) {
+            while (word2[++i] && dIsspace(word2[i])) ;
             Html_process_space(html, word2 + start, i - start);
          } else if (!strncmp(word2+i, utf8_zero_width_space, 3)) {
             i += 3;
@@ -1300,7 +1299,7 @@ static void Html_process_word(DilloHtml 
          } else {
             do {
                i += len;
-            } while (word2[i] && !isspace(word2[i]) &&
+            } while (word2[i] && !dIsspace(word2[i]) &&
                      strncmp(word2+i, utf8_zero_width_space, 3) &&
                      (!a_Utf8_ideographic(word2+i, beyond_word2, &len)));
             HT2TB(html)->addText(word2 + start, i - start, html->wordStyle ());
@@ -1324,7 +1323,7 @@ static bool Html_match_tag(const char *t
          return false;
    }
    /* The test for '/' is for xml compatibility: "empty/>" will be matched. */
-   if (i < tagsize && (isspace(tag[i]) || tag[i] == '>' || tag[i] == '/'))
+   if (i < tagsize && (dIsspace(tag[i]) || tag[i] == '>' || tag[i] == '/'))
       return true;
    return false;
 }
@@ -1441,7 +1440,7 @@ CssLength a_Html_parse_length (DilloHtml
       l = CSS_CREATE_LENGTH(0.0, CSS_LENGTH_TYPE_AUTO);
    else {
       /* allow only whitespaces */
-      if (*end && !isspace (*end)) {
+      if (*end && !dIsspace (*end)) {
          BUG_MSG("Garbage after length: '%s'.", attr);
          l = CSS_CREATE_LENGTH(0.0, CSS_LENGTH_TYPE_AUTO);
       }
@@ -1487,10 +1486,10 @@ static int
       int i;
 
       for (i = 0; val[i]; ++i)
-         if (!d_isascii(val[i]) || !(isalnum(val[i]) || strchr(":_.-", val[i])))
+         if (!d_isascii(val[i]) || !(dIsalnum(val[i]) || strchr(":_.-", val[i])))
             break;
 
-      if (val[i] || !(d_isascii(val[0]) && isalpha(val[0])))
+      if (val[i] || !(d_isascii(val[0]) && dIsalpha(val[0])))
          BUG_MSG("%s attribute value \"%s\" is not of the form "
                  "'[A-Za-z][A-Za-z0-9:_.-]*'.", attrname, val);
 
@@ -1537,8 +1536,8 @@ static void Html_parse_doctype(DilloHtml
    /* Tag sanitization: Collapse whitespace between tokens
     * and replace '\n' and '\r' with ' ' inside quoted strings. */
    for (i = 0, p = ntag; *p; ++p) {
-      if (isspace(*p)) {
-         for (ntag[i++] = ' '; isspace(p[1]); ++p) ;
+      if (dIsspace(*p)) {
+         for (ntag[i++] = ' '; dIsspace(p[1]); ++p) ;
       } else if ((quote = *p) == '"' || *p == '\'') {
          for (ntag[i++] = *p++; (ntag[i] = *p) && ntag[i++] != quote; ++p) {
             if (*p == '\n' || *p == '\r')
@@ -2376,7 +2375,7 @@ misc::SimpleVector<int> *Html_read_coord
          break;
       coords->increase();
       coords->set(coords->size() - 1, coord);
-      while (isspace(*newtail))
+      while (dIsspace(*newtail))
          newtail++;
       if (!*newtail)
          break;
@@ -4178,7 +4177,7 @@ static const char *Html_get_attr2(DilloH
    for (i = 1; i < tagsize; ++i) {
       switch (state) {
       case SEEK_ATTR_START:
-         if (isspace(tag[i]))
+         if (dIsspace(tag[i]))
             state = SEEK_TOKEN_START;
          else if (tag[i] == '=')
             state = SEEK_VALUE_START;
@@ -4186,7 +4185,7 @@ static const char *Html_get_attr2(DilloH
 
       case MATCH_ATTR_NAME:
          if (!attrname[attr_pos] &&
-             (tag[i] == '=' || isspace(tag[i]) || tag[i] == '>')) {
+             (tag[i] == '=' || dIsspace(tag[i]) || tag[i] == '>')) {
             Found = 1;
             state = SEEK_TOKEN_START;
             --i;
@@ -4202,14 +4201,14 @@ static const char *Html_get_attr2(DilloH
       case SEEK_TOKEN_START:
          if (tag[i] == '=') {
             state = SEEK_VALUE_START;
-         } else if (!isspace(tag[i])) {
+         } else if (!dIsspace(tag[i])) {
             attr_pos = 0;
             state = (Found) ? FINISHED : MATCH_ATTR_NAME;
             --i;
          }
          break;
       case SEEK_VALUE_START:
-         if (!isspace(tag[i])) {
+         if (!dIsspace(tag[i])) {
             delimiter = (tag[i] == '"' || tag[i] == '\'') ? tag[i] : ' ';
             i -= (delimiter == ' ');
             state = (Found) ? GET_VALUE : SKIP_VALUE;
@@ -4217,11 +4216,11 @@ static const char *Html_get_attr2(DilloH
          break;
 
       case SKIP_VALUE:
-         if ((delimiter == ' ' && isspace(tag[i])) || tag[i] == delimiter)
+         if ((delimiter == ' ' && dIsspace(tag[i])) || tag[i] == delimiter)
             state = SEEK_TOKEN_START;
          break;
       case GET_VALUE:
-         if ((delimiter == ' ' && (isspace(tag[i]) || tag[i] == '>')) ||
+         if ((delimiter == ' ' && (dIsspace(tag[i]) || tag[i] == '>')) ||
              tag[i] == delimiter) {
             state = FINISHED;
          } else if (tag[i] == '&' &&
@@ -4252,10 +4251,10 @@ static const char *Html_get_attr2(DilloH
    }
 
    if (tag_parsing_flags & HTML_LeftTrim)
-      while (isspace(Buf->str[0]))
+      while (dIsspace(Buf->str[0]))
          dStr_erase(Buf, 0, 1);
    if (tag_parsing_flags & HTML_RightTrim)
-      while (Buf->len && isspace(Buf->str[Buf->len - 1]))
+      while (Buf->len && dIsspace(Buf->str[Buf->len - 1]))
          dStr_truncate(Buf, Buf->len - 1);
 
    return (Found) ? Buf->str : NULL;
@@ -4349,14 +4348,14 @@ static int Html_write_raw(DilloHtml *htm
             break;
       }
 
-      if (isspace(buf[buf_index])) {
+      if (dIsspace(buf[buf_index])) {
          /* whitespace: group all available whitespace */
-         while (++buf_index < bufsize && isspace(buf[buf_index])) ;
+         while (++buf_index < bufsize && dIsspace(buf[buf_index])) ;
          Html_process_space(html, buf + token_start, buf_index - token_start);
          token_start = buf_index;
 
       } else if (buf[buf_index] == '<' && (ch = buf[buf_index + 1]) &&
-                 (isalpha(ch) || strchr("/!?", ch)) ) {
+                 (dIsalpha(ch) || strchr("/!?", ch)) ) {
          /* Tag */
          if (buf_index + 3 < bufsize && !strncmp(buf + buf_index, "<!--", 4)) {
             /* Comment: search for close of comment, skipping over
@@ -4422,7 +4421,7 @@ static int Html_write_raw(DilloHtml *htm
          while (++buf_index < bufsize) {
             buf_index += strcspn(buf + buf_index, " <\n\r\t\f\v");
             if (buf[buf_index] == '<' && (ch = buf[buf_index + 1]) &&
-                !isalpha(ch) && !strchr("/!?", ch))
+                !dIsalpha(ch) && !strchr("/!?", ch))
                continue;
             break;
          }
