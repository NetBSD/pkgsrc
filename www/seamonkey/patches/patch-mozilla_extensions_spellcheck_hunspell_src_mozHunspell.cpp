$NetBSD: patch-mozilla_extensions_spellcheck_hunspell_src_mozHunspell.cpp,v 1.4 2015/09/21 05:03:45 ryoon Exp $

--- mozilla/extensions/spellcheck/hunspell/src/mozHunspell.cpp.orig	2015-09-02 09:28:48.000000000 +0000
+++ mozilla/extensions/spellcheck/hunspell/src/mozHunspell.cpp
@@ -400,6 +400,14 @@ mozHunspell::LoadDictionaryList(bool aNo
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
