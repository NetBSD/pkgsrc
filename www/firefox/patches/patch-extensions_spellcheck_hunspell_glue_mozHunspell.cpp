$NetBSD: patch-extensions_spellcheck_hunspell_glue_mozHunspell.cpp,v 1.1 2015/12/16 09:34:56 ryoon Exp $

--- extensions/spellcheck/hunspell/glue/mozHunspell.cpp.orig	2015-12-04 00:37:13.000000000 +0000
+++ extensions/spellcheck/hunspell/glue/mozHunspell.cpp
@@ -392,6 +392,14 @@ mozHunspell::LoadDictionaryList(bool aNo
     }
   }
 
+  // load system hunspell dictionaries
+  nsCOMPtr<nsIFile> hunDir;
+  NS_NewNativeLocalFile(NS_LITERAL_CSTRING("@PREFIX@/share/hunspell"),
+                        true, getter_AddRefs(hunDir));
+  if (hunDir) {
+      LoadDictionariesFromDir(hunDir);
+  }
+
   // find dictionaries from extensions requiring restart
   nsCOMPtr<nsISimpleEnumerator> dictDirs;
   rv = dirSvc->Get(DICTIONARY_SEARCH_DIRECTORY_LIST,
