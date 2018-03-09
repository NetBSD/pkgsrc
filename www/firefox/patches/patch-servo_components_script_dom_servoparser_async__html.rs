$NetBSD: patch-servo_components_script_dom_servoparser_async__html.rs,v 1.4.2.2 2018/03/09 07:17:30 spz Exp $

--- servo/components/script/dom/servoparser/async_html.rs.orig	2017-11-02 16:16:33.000000000 +0000
+++ servo/components/script/dom/servoparser/async_html.rs
@@ -27,7 +27,6 @@ use html5ever::tokenizer::{Tokenizer as 
 use html5ever::tree_builder::{ElementFlags, NodeOrText as HtmlNodeOrText, NextParserState, QuirksMode, TreeSink};
 use html5ever::tree_builder::{TreeBuilder, TreeBuilderOpts};
 use servo_url::ServoUrl;
-use std::ascii::AsciiExt;
 use std::borrow::Cow;
 use std::cell::Cell;
 use std::collections::HashMap;
