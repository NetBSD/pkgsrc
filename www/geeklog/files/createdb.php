#!@PREFIX@/bin/php
<?php
# $NetBSD: createdb.php,v 1.1.1.1 2006/06/15 13:26:44 taca Exp $
#
# After editing @GEEKLOG_DIR@/config.php,
# execute this script to create new database.
#

require_once( '@GEEKLOG_DIR@/config.php' );

define("MySQL_Admin", "@PREFIX@/bin/mysqladmin");
define("MySQL", "@PREFIX@/bin/mysql");

define("MySQL_Root", "root");

if ($_DB_dbms != "mysql") {
	print("Unknown DBMS: ". $_DB_dbms . "\n");
	exit(1);
}

# Create database.
print "Creating databse for geeklog, please enter DBMS's admin if promped.\n";

$cmd = MySQL_Admin . " --host=" . $_DB_host .
	" --user=" . MySQL_Root . " --password create " . $_DB_name;

print($cmd . "\n");

passthru($cmd, $result);

if ($result != 0) {
	print("Error on creating database, do you want to continue?: ");
	$ans = fgets(STDIN, 10);
	trim($ans);
	if (!eregi("^y", $ans)) {
		print("Abort now\n");
		exit(1);
	}
}

# Create user.
print "\nCreating database user for geeklog, please enter DBMS's admin if promped.\n";

$cmd = MySQL . " --host=" . $_DB_host ." --user=" . MySQL_Root . " --password";
print($cmd . "\n");
$handle = popen($cmd, "w");
if ($handle == FALSE) {
	print("Error on connecting database.\n");
	exit(1);
}

$sql = "GRANT " .
	"SELECT, INSERT, UPDATE, DELETE, CREATE, DROP, INDEX, " .
	"ALTER, CREATE TEMPORARY TABLES, LOCK TABLES" .
	" ON " . $_DB_name . ".* TO '" . $_DB_user . "'@'" . $_DB_host .
	"' IDENTIFIED BY '" . $_DB_pass . "';\n";
# print $sql;
fwrite($handle, $sql);
pclose($handle);

?>
