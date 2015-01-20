$NetBSD: patch-src_OptionContainer.cpp,v 1.1 2015/01/20 11:34:43 prlw1 Exp $

Make per room blocking optional

--- src/OptionContainer.cpp.orig	2012-09-29 20:06:45.000000000 +0000
+++ src/OptionContainer.cpp
@@ -789,10 +789,19 @@ bool OptionContainer::inRoom(const std::
 
 void OptionContainer::loadRooms()
 {
+	if (per_room_blocking_directory_location == "")
+		return;
+ 
 	DIR* d = opendir(per_room_blocking_directory_location.c_str());
 	if (d == NULL)
 	{
-		syslog(LOG_ERR, "Could not open room definitions directory: %s", strerror(errno));
+		if (!is_daemonised) {
+			std::cerr << "Could not open room definitions directory \""
+			          << per_room_blocking_directory_location << '"'
+			          << std::endl;
+		}
+		syslog(LOG_ERR, "Could not open room definitions directory \"%s\": %s",
+		       per_room_blocking_directory_location.c_str(), strerror(errno));
 		exit(1);
 	}
 
@@ -804,11 +813,29 @@ void OptionContainer::loadRooms()
 		std::string filename(per_room_blocking_directory_location);
 		filename.append(f->d_name);
 		std::ifstream infile(filename.c_str());
+		if (!infile.good()) {
+			if (!is_daemonised) {
+				std::cerr << "Could not open room definitions file \""
+				          << filename << '"' << std::endl;
+			}
+			syslog(LOG_ERR, "Could not open room definitions file \"%s\"",
+			       filename.c_str());
+			exit(1);
+		}
 
 		std::string roomname;
 		std::getline(infile, roomname);
 		infile.close();
-		roomname = roomname.substr(1);
+		if (roomname.size() <= 2) {
+			if (!is_daemonised) {
+				std::cerr << "Could not read room from definitions file \""
+				          << filename << '"' << std::endl;
+			}
+			syslog(LOG_ERR, "Could not read room from definitions file \"%s\"",
+			       filename.c_str());
+			exit(1);
+		}
+		roomname = roomname.substr(1); // remove leading '#'
 
 		IPList* contents = new IPList();
 		contents->readIPMelangeList(filename.c_str());
