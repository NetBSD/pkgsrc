$NetBSD: patch-lib_tt_ttinstall.sh,v 1.1 2023/02/13 13:47:33 tnn Exp $

fix double brackets

--- lib/tt/ttinstall.sh.orig	2022-10-01 17:18:27.000000000 +0000
+++ lib/tt/ttinstall.sh
@@ -33,12 +33,12 @@ fi
 function mkdir_p
 {
 # if directory names have trailing /, we get called with a null string	
-	if	[[ "$1" = "" ]]
+	if	[ "$1" = "" ]
 	then	return
 	fi
 # bail out if directory already exists -- this means recursion stops
 # as soon as we back up into an existing directory	
-	if	[[ -d $1 ]]
+	if	[ -d $1 ]
 	then	return
 	fi
 # only recurse if path has a slash in it. 	
@@ -56,7 +56,7 @@ version=$1; shift
 destdir=$1; shift
 datestamp=`date '+%d %h %y'`
 
-if [[ ! -d $destdir ]]
+if [ ! -d $destdir ]
 then	print -n -u2 Creating directory $destdir ...
 	rm -f $destdir
 	mkdir_p $destdir
