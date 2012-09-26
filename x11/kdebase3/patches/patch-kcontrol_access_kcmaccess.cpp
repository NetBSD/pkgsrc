$NetBSD: patch-kcontrol_access_kcmaccess.cpp,v 1.1 2012/09/26 11:10:16 jperkin Exp $

Cast arguments to log().

--- kcontrol/access/kcmaccess.cpp.orig	Wed Sep 26 09:28:31 2012
+++ kcontrol/access/kcmaccess.cpp	Wed Sep 26 09:29:52 2012
@@ -63,13 +63,13 @@
 		this->min = min;
 		this->max = max;
 		sliderMax = (int)floor (0.5
-				+ 2*(log(max)-log(min)) / (log(max)-log(max-1)));
+				+ 2*(log((float)max)-log((float)min)) / (log((float)max)-log((float)max-1)));
 		m_slider->setRange(0, sliderMax);
 		m_slider->setSteps(step, sliderMax/10);
 		m_slider->setTickInterval(sliderMax/10);
 
-		double alpha  = sliderMax / (log(max) - log(min));
-		double logVal = alpha * (log(value())-log(min));
+		double alpha  = sliderMax / (log((float)max) - log((float)min));
+		double logVal = alpha * (log((float)value())-log((float)min));
 		m_slider->setValue ((int)floor (0.5 + logVal));
 
 		connect(m_slider, SIGNAL(valueChanged(int)),
@@ -86,8 +86,8 @@
 {
 
 	if(m_slider) {
-		double alpha  = sliderMax / (log(max) - log(min));
-		double logVal = alpha * (log(val)-log(min));
+		double alpha  = sliderMax / (log((float)max) - log((float)min));
+		double logVal = alpha * (log((float)val)-log((float)min));
 		m_slider->setValue ((int)floor (0.5 + logVal));
 	}
 
@@ -96,8 +96,8 @@
 
 void ExtendedIntNumInput::slotSliderValueChanged(int val)
 {
-	double alpha  = sliderMax / (log(max) - log(min));
-	double linearVal = exp (val/alpha + log(min));
+	double alpha  = sliderMax / (log((float)max) - log((float)min));
+	double linearVal = exp (val/alpha + log((float)min));
 	m_spin->setValue ((int)floor(0.5 + linearVal));
 }
 
