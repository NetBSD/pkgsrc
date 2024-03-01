$NetBSD: patch-weekno.perl,v 1.2 2024/03/01 12:23:07 he Exp $

Fix this so that it uses week numbering according to ISO 8601.
Also replace ' with :: for newer perl.

--- weekno.perl.orig	1995-10-17 13:44:49.000000000 +0000
+++ weekno.perl
@@ -1,7 +1,7 @@
 #!/local/bin/perl
 # Package for date handling
-# Use the PERL std library timelocal - older had his own
-require "timelocal.pl";
+# Use the PERL std package Time::Local
+use Time::Local;
 
 package DATE;
 #               J   F   M   A   M   J   J   A   S   O   N   D
@@ -51,21 +51,36 @@ sub weekno {
 
 
 sub firstdayfirstweek {
-# Return first day of week 1 of any year
+# Return the day of the year (0 is Jan 1st)
+# for the first day of week 1 of any year.
+#
+# Quoting strftime(3):
+#  %V    is replaced by the week number of the year (Monday as the first day
+#        of the week) as a decimal number [01,53]. According to ISO 8601 the
+#        week containing January 1 is week 1 if it has four or more days in
+#        the new year, otherwise it is week 53 of the previous year, and the
+#        next week is week 1.  The year is given by the `%G' conversion
+#        specification.
+#
+# So this will return a negative value in some cases, i.e. when
+# Jan 1st falls on either of Tuesday, Wednesday or Thursday, and
+# will be positive (1) or zero for Sunday or Monday respectively.
+#
    local($y) = @_;
    local($ret);
    # Get time of January 1, 0.0.0.0
    # Note that DST is never in effect on Jan 1...
-   local($firsttime) = &main'timelocal(0, 0, 0, 1, 0, $y, 0, 0, 0);
+   local($firsttime) = &main::timelocal(0, 0, 0, 1, 0, $y, 0, 0, 0);
    local(@firstday) = localtime($firsttime);
    local($wday) = $firstday[6];
-   # Rule works for some years.....89 to 92 tested, they all hit branch 2...
-   if ($wday > 3) {
-      $ret = 8 - $wday;
+   # Weekday 4 is Thursday (localtime returns zero-based with Sunday = 0)
+   if ($wday <= 4) {
+       $ret = 1 - $wday;	# first day of week 1 may be in late December
+       				# The exception is when Jan 1 = Sunday (wday 0)
    } else {
-      $ret = 1 - $wday;
+       $ret = 8 - $wday;	# first day of week 1 is in January
    }
-   $ret;
+   return $ret;
 }
  
 sub firstinweek {
@@ -73,7 +88,7 @@ sub firstinweek {
 # (to avoid DST troubles)
    local($weekno, $year) = @_;
    # 2 hours into this year
-   local($time) = &main'timelocal(0, 0, 2, 1, 0, $year, 0, 0, 0);
+   local($time) = &main::timelocal(0, 0, 2, 1, 0, $year, 0, 0, 0);
    # Add number of days since start of year
    $time += (($weekno - 1) * 7 + &firstdayfirstweek($year)) * 60 * 60 * 24;
    $time;
