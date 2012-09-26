$NetBSD: patch-kxkb_kcmmisc.cpp,v 1.1 2012/09/26 11:10:17 jperkin Exp $

Cast calls to log().

--- kxkb/kcmmisc.cpp.orig	Wed Sep 26 08:57:08 2012
+++ kxkb/kcmmisc.cpp	Wed Sep 26 09:05:19 2012
@@ -64,7 +64,7 @@
   ui->rate->setRange(0.2, 50, 5, false);
 
   sliderMax = (int)floor (0.5
-		  + 2*(log(5000)-log(100)) / (log(5000)-log(4999)));
+		  + 2*(log((float)5000)-log((float)100)) / (log((float)5000)-log((float)4999)));
   ui->delaySlider->setRange(0, sliderMax);
   ui->delaySlider->setSteps(sliderMax/100, sliderMax/10);
   ui->delaySlider->setTickInterval(sliderMax/10);
@@ -196,8 +196,8 @@
 }
 
 void KeyboardConfig::delaySliderChanged (int value) {
-	double alpha  = sliderMax / (log(5000) - log(100));
-	double linearValue = exp (value/alpha + log(100));
+	double alpha  = sliderMax / (log((float)5000) - log((float)100));
+	double linearValue = exp (value/alpha + log((float)100));
 
 	ui->delay->setValue((int)floor(0.5 + linearValue));
 
@@ -205,8 +205,8 @@
 }
 
 void KeyboardConfig::delaySpinboxChanged (int value) {
-	double alpha  = sliderMax / (log(5000) - log(100));
-	double logVal = alpha * (log(value)-log(100));
+	double alpha  = sliderMax / (log((float)5000) - log((float)100));
+	double logVal = alpha * (log((float)value)-log((float)100));
 
 	ui->delaySlider->setValue ((int)floor (0.5 + logVal));
 
