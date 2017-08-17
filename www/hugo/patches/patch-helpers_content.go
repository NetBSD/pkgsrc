$NetBSD: patch-helpers_content.go,v 1.1 2017/08/17 01:50:26 gavan Exp $

--- helpers/content.go.orig	2017-08-07 07:09:19.000000000 +0000
+++ helpers/content.go
@@ -131,7 +131,6 @@ var blackfridayExtensionMap = map[string
 	"autoHeaderIds":          blackfriday.EXTENSION_AUTO_HEADER_IDS,
 	"backslashLineBreak":     blackfriday.EXTENSION_BACKSLASH_LINE_BREAK,
 	"definitionLists":        blackfriday.EXTENSION_DEFINITION_LISTS,
-	"joinLines":              blackfriday.EXTENSION_JOIN_LINES,
 }
 
 var stripHTMLReplacer = strings.NewReplacer("\n", " ", "</p>", "\n", "<br>", "\n", "<br />", "\n")
@@ -223,10 +222,6 @@ func (c ContentSpec) getHTMLRenderer(def
 		htmlFlags |= blackfriday.HTML_USE_SMARTYPANTS
 	}
 
-	if ctx.Config.SmartypantsQuotesNBSP {
-		htmlFlags |= blackfriday.HTML_SMARTYPANTS_QUOTES_NBSP
-	}
-
 	if ctx.Config.AngledQuotes {
 		htmlFlags |= blackfriday.HTML_SMARTYPANTS_ANGLED_QUOTES
 	}
