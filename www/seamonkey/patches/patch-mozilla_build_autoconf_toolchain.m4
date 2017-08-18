$NetBSD: patch-mozilla_build_autoconf_toolchain.m4,v 1.1 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/build/autoconf/toolchain.m4.orig	2017-07-07 05:35:47.000000000 +0000
+++ mozilla/build/autoconf/toolchain.m4
@@ -2,14 +2,6 @@ dnl This Source Code Form is subject to 
 dnl License, v. 2.0. If a copy of the MPL was not distributed with this
 dnl file, You can obtain one at http://mozilla.org/MPL/2.0/.
 
-dnl Several autoconf functions AC_REQUIRE AC_PROG_CPP/AC_PROG_CXXCPP,
-dnl meaning they are called even when we don't call them explicitly.
-dnl However, theses checks are not necessary and python configure sets
-dnl the corresponding variables already, so just skip those tests
-dnl entirely.
-define([AC_PROG_CPP],[])
-define([AC_PROG_CXXCPP],[])
-
 AC_DEFUN([MOZ_TOOL_VARIABLES],
 [
 GNU_AS=
