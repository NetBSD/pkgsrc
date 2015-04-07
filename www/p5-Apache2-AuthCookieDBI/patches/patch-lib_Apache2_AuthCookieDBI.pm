$NetBSD: patch-lib_Apache2_AuthCookieDBI.pm,v 1.1 2015/04/07 08:06:14 he Exp $

Quoting database identifiers with backticks as is done in 2.17 is
not portable, and only works with a MySQL backend.  Instead, use
the DBI quote_identifier method as hinted in
https://rt.cpan.org/Public/Bug/Display.html?id=101561

--- lib/Apache2/AuthCookieDBI.pm.orig	2012-12-06 03:41:41.000000000 +0000
+++ lib/Apache2/AuthCookieDBI.pm
@@ -615,12 +615,16 @@ sub _get_crypted_password {
 
     my $crypted_password = EMPTY_STRING;
 
+    my $PasswordField = $dbh->quote_identifier($c{'DBI_PasswordField'});
+    my $UsersTable = $dbh->quote_identifier($c{'DBI_UsersTable'});
+    my $UserField = $dbh->quote_identifier($c{'DBI_UserField'});
+
     my $sql_query = <<"SQL";
-      SELECT `$c{'DBI_PasswordField'}`
-      FROM `$c{'DBI_UsersTable'}`
-      WHERE `$c{'DBI_UserField'}` = ?
-      AND (`$c{'DBI_PasswordField'}` != ''
-      AND `$c{'DBI_PasswordField'}` IS NOT NULL)
+      SELECT $PasswordField
+      FROM $UsersTable
+      WHERE $UserField = ?
+      AND ($PasswordField != ''
+      AND $PasswordField IS NOT NULL)
 SQL
     my $sth = $dbh->prepare_cached($sql_query);
     $sth->execute($user);
@@ -964,11 +968,15 @@ sub group {
     my $dbh = $class->_dbi_connect($r) || return Apache2::Const::SERVER_ERROR;
 
     # Now loop through all the groups to see if we're a member of any:
+    my $DBI_GroupUserField = $dbh->quote_identifier($c{'DBI_GroupUserField'});
+    my $DBI_GroupsTable = $dbh->quote_identifier($c{'DBI_GroupsTable'});
+    my $DBI_GroupField = $dbh->quote_identifier($c{'DBI_GroupField'});
+
     my $sth = $dbh->prepare_cached( <<"EOS" );
-SELECT `$c{'DBI_GroupUserField'}`
-FROM `$c{'DBI_GroupsTable'}`
-WHERE `$c{'DBI_GroupField'}` = ?
-AND `$c{'DBI_GroupUserField'}` = ?
+SELECT $DBI_GroupUserField
+FROM $DBI_GroupsTable
+WHERE $DBI_GroupField = ?
+AND $DBI_GroupUserField = ?
 EOS
     foreach my $group (@groups) {
         $sth->execute( $group, $user );
@@ -999,10 +1007,14 @@ sub user_is_active {
     }
 
     my $dbh = $class->_dbi_connect($r) || return;
+    my $ActiveFieldName = $dbh->quote_identifier($active_field_name);
+    my $DBI_UsersTable = $dbh->quote_identifier($c{'DBI_UsersTable'});
+    my $DBI_UserField  = $dbh->quote_identifier($c{'DBI_UserField'});
+
     my $sql_query = <<"SQL";
-      SELECT `$active_field_name`
-      FROM `$c{'DBI_UsersTable'}`
-      WHERE `$c{'DBI_UserField'}` = ?
+      SELECT $ActiveFieldName
+      FROM $DBI_UsersTable
+      WHERE $DBI_UserField = ?
 SQL
 
     my $sth = $dbh->prepare_cached($sql_query);
