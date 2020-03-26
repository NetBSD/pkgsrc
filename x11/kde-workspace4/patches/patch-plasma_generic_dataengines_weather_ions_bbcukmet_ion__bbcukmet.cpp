$NetBSD: patch-plasma_generic_dataengines_weather_ions_bbcukmet_ion__bbcukmet.cpp,v 1.1 2020/03/26 21:48:12 joerg Exp $

--- plasma/generic/dataengines/weather/ions/bbcukmet/ion_bbcukmet.cpp.orig	2020-03-26 12:09:14.941435215 +0000
+++ plasma/generic/dataengines/weather/ions/bbcukmet/ion_bbcukmet.cpp
@@ -312,11 +312,11 @@ void UKMETIon::readSearchHTMLData(const 
 
     while (!stream.atEnd()) {
        line = stream.readLine();
-       if (line.contains("<p class=\"response\">") > 0) {
+       if (line.contains("<p class=\"response\">")) {
            flag = 1;
        }
 
-       if (line.contains("There are no forecasts matching") > 0) {
+       if (line.contains("There are no forecasts matching")) {
            break;
        }
 
@@ -342,7 +342,7 @@ void UKMETIon::readSearchHTMLData(const 
             }
        }
 
-       if (line.contains("<div class=\"line\">") > 0) {
+       if (line.contains("<div class=\"line\">")) {
            flag = 0;
        }
     }
