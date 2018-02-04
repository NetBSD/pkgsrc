$NetBSD: patch-klinkstatus_src_tidy_tidyx.h,v 1.2 2018/02/04 00:23:08 markd Exp $

tidy-5.x compatibility.

--- klinkstatus/src/tidy/tidyx.h.orig	2008-07-28 16:04:32.000000000 +0000
+++ klinkstatus/src/tidy/tidyx.h
@@ -49,7 +49,7 @@
 */
 
 #include <tidy.h>
-#include <buffio.h>
+#include <tidybuffio.h>
 
 #include <config-tidy.h>
     
@@ -303,6 +303,8 @@ public:
     ctmbstr NsUri()      { return tidyNodeNsUri( tnod() ); }
     */
 
+#define return_(a) return((a) ? yes : no)
+
     /* Iterate over attribute values */
     AttrVal* FirstAttr() { return (AttrVal*) tidyAttrFirst( tnod() ); }
 
@@ -312,134 +314,134 @@ public:
 
     TagId Id()           { return tidyNodeGetId( tnod() ); }
 
-    Bool IsHTML()        { return tidyNodeIsHTML( tnod() ); }
-    Bool IsHEAD()        { return tidyNodeIsHEAD( tnod() ); }
-    Bool IsTITLE()       { return tidyNodeIsTITLE( tnod() ); }
-    Bool IsBASE()        { return tidyNodeIsBASE( tnod() ); }
-    Bool IsMETA()        { return tidyNodeIsMETA( tnod() ); }
-    Bool IsBODY()        { return tidyNodeIsBODY( tnod() ); }
-    Bool IsFRAMESET()    { return tidyNodeIsFRAMESET( tnod() ); }
-    Bool IsFRAME()       { return tidyNodeIsFRAME( tnod() ); }
-    Bool IsIFRAME()      { return tidyNodeIsIFRAME( tnod() ); }
-    Bool IsNOFRAMES()    { return tidyNodeIsNOFRAMES( tnod() ); }
-    Bool IsHR()          { return tidyNodeIsHR( tnod() ); }
-    Bool IsH1()          { return tidyNodeIsH1( tnod() ); }
-    Bool IsH2()          { return tidyNodeIsH2( tnod() ); }
-    Bool IsPRE()         { return tidyNodeIsPRE( tnod() ); }
-    Bool IsLISTING()     { return tidyNodeIsLISTING( tnod() ); }
-    Bool IsP()           { return tidyNodeIsP( tnod() ); }
-    Bool IsUL()          { return tidyNodeIsUL( tnod() ); }
-    Bool IsOL()          { return tidyNodeIsOL( tnod() ); }
-    Bool IsDL()          { return tidyNodeIsDL( tnod() ); }
-    Bool IsDIR()         { return tidyNodeIsDIR( tnod() ); }
-    Bool IsLI()          { return tidyNodeIsLI( tnod() ); }
-    Bool IsDT()          { return tidyNodeIsDT( tnod() ); }
-    Bool IsDD()          { return tidyNodeIsDD( tnod() ); }
-    Bool IsTABLE()       { return tidyNodeIsTABLE( tnod() ); }
-    Bool IsCAPTION()     { return tidyNodeIsCAPTION( tnod() ); }
-    Bool IsTD()          { return tidyNodeIsTD( tnod() ); }
-    Bool IsTH()          { return tidyNodeIsTH( tnod() ); }
-    Bool IsTR()          { return tidyNodeIsTR( tnod() ); }
-    Bool IsCOL()         { return tidyNodeIsCOL( tnod() ); }
-    Bool IsCOLGROUP()    { return tidyNodeIsCOLGROUP( tnod() ); }
-    Bool IsBR()          { return tidyNodeIsBR( tnod() ); }
-    Bool IsA()           { return tidyNodeIsA( tnod() ); }
-    Bool IsLINK()        { return tidyNodeIsLINK( tnod() ); }
-    Bool IsB()           { return tidyNodeIsB( tnod() ); }
-    Bool IsI()           { return tidyNodeIsI( tnod() ); }
-    Bool IsSTRONG()      { return tidyNodeIsSTRONG( tnod() ); }
-    Bool IsEM()          { return tidyNodeIsEM( tnod() ); }
-    Bool IsBIG()         { return tidyNodeIsBIG( tnod() ); }
-    Bool IsSMALL()       { return tidyNodeIsSMALL( tnod() ); }
-    Bool IsPARAM()       { return tidyNodeIsPARAM( tnod() ); }
-    Bool IsOPTION()      { return tidyNodeIsOPTION( tnod() ); }
-    Bool IsOPTGROUP()    { return tidyNodeIsOPTGROUP( tnod() ); }
-    Bool IsIMG()         { return tidyNodeIsIMG( tnod() ); }
-    Bool IsMAP()         { return tidyNodeIsMAP( tnod() ); }
-    Bool IsAREA()        { return tidyNodeIsAREA( tnod() ); }
-    Bool IsNOBR()        { return tidyNodeIsNOBR( tnod() ); }
-    Bool IsWBR()         { return tidyNodeIsWBR( tnod() ); }
-    Bool IsFONT()        { return tidyNodeIsFONT( tnod() ); }
-    Bool IsLAYER()       { return tidyNodeIsLAYER( tnod() ); }
-    Bool IsSPACER()      { return tidyNodeIsSPACER( tnod() ); }
-    Bool IsCENTER()      { return tidyNodeIsCENTER( tnod() ); }
-    Bool IsSTYLE()       { return tidyNodeIsSTYLE( tnod() ); }
-    Bool IsSCRIPT()      { return tidyNodeIsSCRIPT( tnod() ); }
-    Bool IsNOSCRIPT()    { return tidyNodeIsNOSCRIPT( tnod() ); }
-    Bool IsFORM()        { return tidyNodeIsFORM( tnod() ); }
-    Bool IsTEXTAREA()    { return tidyNodeIsTEXTAREA( tnod() ); }
-    Bool IsBLOCKQUOTE()  { return tidyNodeIsBLOCKQUOTE( tnod() ); }
-    Bool IsAPPLET()      { return tidyNodeIsAPPLET( tnod() ); }
-    Bool IsOBJECT()      { return tidyNodeIsOBJECT( tnod() ); }
-    Bool IsDIV()         { return tidyNodeIsDIV( tnod() ); }
-    Bool IsSPAN()        { return tidyNodeIsSPAN( tnod() ); }
-    Bool IsINPUT()       { return tidyNodeIsINPUT( tnod() ); }
-    Bool IsQ()           { return tidyNodeIsQ( tnod() ); }
-    Bool IsLABEL()       { return tidyNodeIsLABEL( tnod() ); }
-    Bool IsH3()          { return tidyNodeIsH3( tnod() ); }
-    Bool IsH4()          { return tidyNodeIsH4( tnod() ); }
-    Bool IsH5()          { return tidyNodeIsH5( tnod() ); }
-    Bool IsH6()          { return tidyNodeIsH6( tnod() ); }
-    Bool IsADDRESS()     { return tidyNodeIsADDRESS( tnod() ); }
-    Bool IsXMP()         { return tidyNodeIsXMP( tnod() ); }
-    Bool IsSELECT()      { return tidyNodeIsSELECT( tnod() ); }
-    Bool IsBLINK()       { return tidyNodeIsBLINK( tnod() ); }
-    Bool IsMARQUEE()     { return tidyNodeIsMARQUEE( tnod() ); }
-    Bool IsEMBED()       { return tidyNodeIsEMBED( tnod() ); }
-    Bool IsBASEFONT()    { return tidyNodeIsBASEFONT( tnod() ); }
-    Bool IsISINDEX()     { return tidyNodeIsISINDEX( tnod() ); }
-    Bool IsS()           { return tidyNodeIsS( tnod() ); }
-    Bool IsSTRIKE()      { return tidyNodeIsSTRIKE( tnod() ); }
-    Bool IsU()           { return tidyNodeIsU( tnod() ); }
-    Bool IsMENU()        { return tidyNodeIsMENU( tnod() ); }
+    Bool IsHTML()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_HTML); }
+    Bool IsHEAD()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_HEAD); }
+    Bool IsTITLE()       { return_ (tidyNodeGetId( tnod() ) == TidyTag_TITLE); }
+    Bool IsBASE()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_BASE); }
+    Bool IsMETA()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_META); }
+    Bool IsBODY()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_BODY); }
+    Bool IsFRAMESET()    { return_ (tidyNodeGetId( tnod() ) == TidyTag_FRAMESET); }
+    Bool IsFRAME()       { return_ (tidyNodeGetId( tnod() ) == TidyTag_FRAME); }
+    Bool IsIFRAME()      { return_ (tidyNodeGetId( tnod() ) == TidyTag_IFRAME); }
+    Bool IsNOFRAMES()    { return_ (tidyNodeGetId( tnod() ) == TidyTag_NOFRAMES); }
+    Bool IsHR()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_HR); }
+    Bool IsH1()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_H1); }
+    Bool IsH2()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_H2); }
+    Bool IsPRE()         { return_ (tidyNodeGetId( tnod() ) == TidyTag_PRE); }
+    Bool IsLISTING()     { return_ (tidyNodeGetId( tnod() ) == TidyTag_LISTING); }
+    Bool IsP()           { return_ (tidyNodeGetId( tnod() ) == TidyTag_P); }
+    Bool IsUL()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_UL); }
+    Bool IsOL()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_OL); }
+    Bool IsDL()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_DL); }
+    Bool IsDIR()         { return_ (tidyNodeGetId( tnod() ) == TidyTag_DIR); }
+    Bool IsLI()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_LI); }
+    Bool IsDT()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_DT); }
+    Bool IsDD()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_DD); }
+    Bool IsTABLE()       { return_ (tidyNodeGetId( tnod() ) == TidyTag_TABLE); }
+    Bool IsCAPTION()     { return_ (tidyNodeGetId( tnod() ) == TidyTag_CAPTION); }
+    Bool IsTD()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_TD); }
+    Bool IsTH()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_TH); }
+    Bool IsTR()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_TR); }
+    Bool IsCOL()         { return_ (tidyNodeGetId( tnod() ) == TidyTag_COL); }
+    Bool IsCOLGROUP()    { return_ (tidyNodeGetId( tnod() ) == TidyTag_COLGROUP); }
+    Bool IsBR()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_BR); }
+    Bool IsA()           { return_ (tidyNodeGetId( tnod() ) == TidyTag_A); }
+    Bool IsLINK()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_LINK); }
+    Bool IsB()           { return_ (tidyNodeGetId( tnod() ) == TidyTag_B); }
+    Bool IsI()           { return_ (tidyNodeGetId( tnod() ) == TidyTag_I); }
+    Bool IsSTRONG()      { return_ (tidyNodeGetId( tnod() ) == TidyTag_STRONG); }
+    Bool IsEM()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_EM); }
+    Bool IsBIG()         { return_ (tidyNodeGetId( tnod() ) == TidyTag_BIG); }
+    Bool IsSMALL()       { return_ (tidyNodeGetId( tnod() ) == TidyTag_SMALL); }
+    Bool IsPARAM()       { return_ (tidyNodeGetId( tnod() ) == TidyTag_PARAM); }
+    Bool IsOPTION()      { return_ (tidyNodeGetId( tnod() ) == TidyTag_OPTION); }
+    Bool IsOPTGROUP()    { return_ (tidyNodeGetId( tnod() ) == TidyTag_OPTGROUP); }
+    Bool IsIMG()         { return_ (tidyNodeGetId( tnod() ) == TidyTag_IMG); }
+    Bool IsMAP()         { return_ (tidyNodeGetId( tnod() ) == TidyTag_MAP); }
+    Bool IsAREA()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_AREA); }
+    Bool IsNOBR()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_NOBR); }
+    Bool IsWBR()         { return_ (tidyNodeGetId( tnod() ) == TidyTag_WBR); }
+    Bool IsFONT()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_FONT); }
+    Bool IsLAYER()       { return_ (tidyNodeGetId( tnod() ) == TidyTag_LAYER); }
+    Bool IsSPACER()      { return_ (tidyNodeGetId( tnod() ) == TidyTag_SPACER); }
+    Bool IsCENTER()      { return_ (tidyNodeGetId( tnod() ) == TidyTag_CENTER); }
+    Bool IsSTYLE()       { return_ (tidyNodeGetId( tnod() ) == TidyTag_STYLE); }
+    Bool IsSCRIPT()      { return_ (tidyNodeGetId( tnod() ) == TidyTag_SCRIPT); }
+    Bool IsNOSCRIPT()    { return_ (tidyNodeGetId( tnod() ) == TidyTag_NOSCRIPT); }
+    Bool IsFORM()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_FORM); }
+    Bool IsTEXTAREA()    { return_ (tidyNodeGetId( tnod() ) == TidyTag_TEXTAREA); }
+    Bool IsBLOCKQUOTE()  { return_ (tidyNodeGetId( tnod() ) == TidyTag_BLOCKQUOTE); }
+    Bool IsAPPLET()      { return_ (tidyNodeGetId( tnod() ) == TidyTag_APPLET); }
+    Bool IsOBJECT()      { return_ (tidyNodeGetId( tnod() ) == TidyTag_OBJECT); }
+    Bool IsDIV()         { return_ (tidyNodeGetId( tnod() ) == TidyTag_DIV); }
+    Bool IsSPAN()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_SPAN); }
+    Bool IsINPUT()       { return_ (tidyNodeGetId( tnod() ) == TidyTag_INPUT); }
+    Bool IsQ()           { return_ (tidyNodeGetId( tnod() ) == TidyTag_Q); }
+    Bool IsLABEL()       { return_ (tidyNodeGetId( tnod() ) == TidyTag_LABEL); }
+    Bool IsH3()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_H3); }
+    Bool IsH4()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_H4); }
+    Bool IsH5()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_H5); }
+    Bool IsH6()          { return_ (tidyNodeGetId( tnod() ) == TidyTag_H6); }
+    Bool IsADDRESS()     { return_ (tidyNodeGetId( tnod() ) == TidyTag_ADDRESS); }
+    Bool IsXMP()         { return_ (tidyNodeGetId( tnod() ) == TidyTag_XMP); }
+    Bool IsSELECT()      { return_ (tidyNodeGetId( tnod() ) == TidyTag_SELECT); }
+    Bool IsBLINK()       { return_ (tidyNodeGetId( tnod() ) == TidyTag_BLINK); }
+    Bool IsMARQUEE()     { return_ (tidyNodeGetId( tnod() ) == TidyTag_MARQUEE); }
+    Bool IsEMBED()       { return_ (tidyNodeGetId( tnod() ) == TidyTag_EMBED); }
+    Bool IsBASEFONT()    { return_ (tidyNodeGetId( tnod() ) == TidyTag_BASEFONT); }
+    Bool IsISINDEX()     { return_ (tidyNodeGetId( tnod() ) == TidyTag_ISINDEX); }
+    Bool IsS()           { return_ (tidyNodeGetId( tnod() ) == TidyTag_S); }
+    Bool IsSTRIKE()      { return_ (tidyNodeGetId( tnod() ) == TidyTag_STRIKE); }
+    Bool IsU()           { return_ (tidyNodeGetId( tnod() ) == TidyTag_U); }
+    Bool IsMENU()        { return_ (tidyNodeGetId( tnod() ) == TidyTag_MENU); }
 
     /* Attribute retrieval
     */
-    AttrVal* GetHREF()        { return attr(tidyAttrGetHREF( tnod() )); }
-    AttrVal* GetSRC()         { return attr(tidyAttrGetSRC( tnod() )); }
-    AttrVal* GetID()          { return attr(tidyAttrGetID( tnod() )); }
-    AttrVal* GetNAME()        { return attr(tidyAttrGetNAME( tnod() )); }
-    AttrVal* GetSUMMARY()     { return attr(tidyAttrGetSUMMARY( tnod() )); }
-    AttrVal* GetALT()         { return attr(tidyAttrGetALT( tnod() )); }
-    AttrVal* GetLONGDESC()    { return attr(tidyAttrGetLONGDESC( tnod() )); }
-    AttrVal* GetUSEMAP()      { return attr(tidyAttrGetUSEMAP( tnod() )); }
-    AttrVal* GetISMAP()       { return attr(tidyAttrGetISMAP( tnod() )); }
-    AttrVal* GetLANGUAGE()    { return attr(tidyAttrGetLANGUAGE( tnod() )); }
-    AttrVal* GetTYPE()        { return attr(tidyAttrGetTYPE( tnod() )); }
-    AttrVal* GetVALUE()       { return attr(tidyAttrGetVALUE( tnod() )); }
-    AttrVal* GetCONTENT()     { return attr(tidyAttrGetCONTENT( tnod() )); }
-    AttrVal* GetTITLE()       { return attr(tidyAttrGetTITLE( tnod() )); }
-    AttrVal* GetXMLNS()       { return attr(tidyAttrGetXMLNS( tnod() )); }
-    AttrVal* GetDATAFLD()     { return attr(tidyAttrGetDATAFLD( tnod() )); }
-    AttrVal* GetWIDTH()       { return attr(tidyAttrGetWIDTH( tnod() )); }
-    AttrVal* GetHEIGHT()      { return attr(tidyAttrGetHEIGHT( tnod() )); }
-    AttrVal* GetFOR()         { return attr(tidyAttrGetFOR( tnod() )); }
-    AttrVal* GetSELECTED()    { return attr(tidyAttrGetSELECTED( tnod() )); }
-    AttrVal* GetCHECKED()     { return attr(tidyAttrGetCHECKED( tnod() )); }
-    AttrVal* GetLANG()        { return attr(tidyAttrGetLANG( tnod() )); }
-    AttrVal* GetTARGET()      { return attr(tidyAttrGetTARGET( tnod() )); }
-    AttrVal* GetHTTP_EQUIV()  { return attr(tidyAttrGetHTTP_EQUIV(tnod())); }
-    AttrVal* GetREL()         { return attr(tidyAttrGetREL( tnod() )); }
-    AttrVal* GetOnMOUSEMOVE() { return attr(tidyAttrGetOnMOUSEMOVE(tnod())); }
-    AttrVal* GetOnMOUSEDOWN() { return attr(tidyAttrGetOnMOUSEDOWN(tnod())); }
-    AttrVal* GetOnMOUSEUP()   { return attr(tidyAttrGetOnMOUSEUP( tnod() )); }
-    AttrVal* GetOnCLICK()     { return attr(tidyAttrGetOnCLICK( tnod() )); }
-    AttrVal* GetOnMOUSEOVER() { return attr(tidyAttrGetOnMOUSEOVER(tnod())); }
-    AttrVal* GetOnMOUSEOUT()  { return attr(tidyAttrGetOnMOUSEOUT(tnod())); }
-    AttrVal* GetOnKEYDOWN()   { return attr(tidyAttrGetOnKEYDOWN( tnod() )); }
-    AttrVal* GetOnKEYUP()     { return attr(tidyAttrGetOnKEYUP( tnod() )); }
-    AttrVal* GetOnKEYPRESS()  { return attr(tidyAttrGetOnKEYPRESS(tnod())); }
-    AttrVal* GetOnFOCUS()     { return attr(tidyAttrGetOnFOCUS( tnod() )); }
-    AttrVal* GetOnBLUR()      { return attr(tidyAttrGetOnBLUR( tnod() )); }
-    AttrVal* GetBGCOLOR()     { return attr(tidyAttrGetBGCOLOR( tnod() )); }
-    AttrVal* GetLINK()        { return attr(tidyAttrGetLINK( tnod() )); }
-    AttrVal* GetALINK()       { return attr(tidyAttrGetALINK( tnod() )); }
-    AttrVal* GetVLINK()       { return attr(tidyAttrGetVLINK( tnod() )); }
-    AttrVal* GetTEXT()        { return attr(tidyAttrGetTEXT( tnod() )); }
-    AttrVal* GetSTYLE()       { return attr(tidyAttrGetSTYLE( tnod() )); }
-    AttrVal* GetABBR()        { return attr(tidyAttrGetABBR( tnod() )); }
-    AttrVal* GetCOLSPAN()     { return attr(tidyAttrGetCOLSPAN( tnod() )); }
-    AttrVal* GetROWSPAN()     { return attr(tidyAttrGetROWSPAN( tnod() )); }
+    AttrVal* GetHREF()        { return attr(tidyAttrGetById( tnod(), TidyAttr_HREF )); }
+    AttrVal* GetSRC()         { return attr(tidyAttrGetById( tnod(), TidyAttr_SRC)); }
+    AttrVal* GetID()          { return attr(tidyAttrGetById( tnod(), TidyAttr_ID )); }
+    AttrVal* GetNAME()        { return attr(tidyAttrGetById( tnod(), TidyAttr_NAME )); }
+    AttrVal* GetSUMMARY()     { return attr(tidyAttrGetById( tnod(), TidyAttr_SUMMARY )); }
+    AttrVal* GetALT()         { return attr(tidyAttrGetById( tnod(), TidyAttr_ALT )); }
+    AttrVal* GetLONGDESC()    { return attr(tidyAttrGetById( tnod(), TidyAttr_LONGDESC )); }
+    AttrVal* GetUSEMAP()      { return attr(tidyAttrGetById( tnod(), TidyAttr_USEMAP )); }
+    AttrVal* GetISMAP()       { return attr(tidyAttrGetById( tnod(), TidyAttr_ISMAP )); }
+    AttrVal* GetLANGUAGE()    { return attr(tidyAttrGetById( tnod(), TidyAttr_LANGUAGE )); }
+    AttrVal* GetTYPE()        { return attr(tidyAttrGetById( tnod(), TidyAttr_TYPE )); }
+    AttrVal* GetVALUE()       { return attr(tidyAttrGetById( tnod(), TidyAttr_VALUE )); }
+    AttrVal* GetCONTENT()     { return attr(tidyAttrGetById( tnod(), TidyAttr_CONTENT )); }
+    AttrVal* GetTITLE()       { return attr(tidyAttrGetById( tnod(), TidyAttr_TITLE )); }
+    AttrVal* GetXMLNS()       { return attr(tidyAttrGetById( tnod(), TidyAttr_XMLNS )); }
+    AttrVal* GetDATAFLD()     { return attr(tidyAttrGetById( tnod(), TidyAttr_DATAFLD )); }
+    AttrVal* GetWIDTH()       { return attr(tidyAttrGetById( tnod(), TidyAttr_WIDTH )); }
+    AttrVal* GetHEIGHT()      { return attr(tidyAttrGetById( tnod(), TidyAttr_HEIGHT )); }
+    AttrVal* GetFOR()         { return attr(tidyAttrGetById( tnod(), TidyAttr_FOR )); }
+    AttrVal* GetSELECTED()    { return attr(tidyAttrGetById( tnod(), TidyAttr_SELECTED )); }
+    AttrVal* GetCHECKED()     { return attr(tidyAttrGetById( tnod(), TidyAttr_CHECKED )); }
+    AttrVal* GetLANG()        { return attr(tidyAttrGetById( tnod(), TidyAttr_LANG )); }
+    AttrVal* GetTARGET()      { return attr(tidyAttrGetById( tnod(), TidyAttr_TARGET )); }
+    AttrVal* GetHTTP_EQUIV()  { return attr(tidyAttrGetById(tnod(), TidyAttr_HTTP_EQUIV)); }
+    AttrVal* GetREL()         { return attr(tidyAttrGetById( tnod(), TidyAttr_REL )); }
+    AttrVal* GetOnMOUSEMOVE() { return attr(tidyAttrGetById(tnod(), TidyAttr_OnMOUSEMOVE)); }
+    AttrVal* GetOnMOUSEDOWN() { return attr(tidyAttrGetById(tnod(), TidyAttr_OnMOUSEDOWN)); }
+    AttrVal* GetOnMOUSEUP()   { return attr(tidyAttrGetById( tnod(), TidyAttr_OnMOUSEUP )); }
+    AttrVal* GetOnCLICK()     { return attr(tidyAttrGetById( tnod(), TidyAttr_OnCLICK )); }
+    AttrVal* GetOnMOUSEOVER() { return attr(tidyAttrGetById(tnod(), TidyAttr_OnMOUSEOVER)); }
+    AttrVal* GetOnMOUSEOUT()  { return attr(tidyAttrGetById(tnod(), TidyAttr_OnMOUSEOUT)); }
+    AttrVal* GetOnKEYDOWN()   { return attr(tidyAttrGetById( tnod(), TidyAttr_OnKEYDOWN )); }
+    AttrVal* GetOnKEYUP()     { return attr(tidyAttrGetById( tnod(), TidyAttr_OnKEYUP )); }
+    AttrVal* GetOnKEYPRESS()  { return attr(tidyAttrGetById(tnod(), TidyAttr_OnKEYPRESS)); }
+    AttrVal* GetOnFOCUS()     { return attr(tidyAttrGetById( tnod(), TidyAttr_OnFOCUS )); }
+    AttrVal* GetOnBLUR()      { return attr(tidyAttrGetById( tnod(), TidyAttr_OnBLUR )); }
+    AttrVal* GetBGCOLOR()     { return attr(tidyAttrGetById( tnod(), TidyAttr_BGCOLOR )); }
+    AttrVal* GetLINK()        { return attr(tidyAttrGetById( tnod(), TidyAttr_LINK )); }
+    AttrVal* GetALINK()       { return attr(tidyAttrGetById( tnod(), TidyAttr_ALINK )); }
+    AttrVal* GetVLINK()       { return attr(tidyAttrGetById( tnod(), TidyAttr_VLINK )); }
+    AttrVal* GetTEXT()        { return attr(tidyAttrGetById( tnod(), TidyAttr_TEXT )); }
+    AttrVal* GetSTYLE()       { return attr(tidyAttrGetById( tnod(), TidyAttr_STYLE )); }
+    AttrVal* GetABBR()        { return attr(tidyAttrGetById( tnod(), TidyAttr_ABBR )); }
+    AttrVal* GetCOLSPAN()     { return attr(tidyAttrGetById( tnod(), TidyAttr_COLSPAN )); }
+    AttrVal* GetROWSPAN()     { return attr(tidyAttrGetById( tnod(), TidyAttr_ROWSPAN)); }
 
 protected:
     AttrVal* attr( TidyAttr tattr )
@@ -472,53 +474,53 @@ public:
 
     AttrId Id()            { return tidyAttrGetId( tattr() ); }
     Bool IsEvent()         { return tidyAttrIsEvent( tattr() ); }
-    Bool IsProp()          { return tidyAttrIsProp( tattr() ); }
+    Bool IsProp()          { return_(tidyAttrGetId( tattr() ) == TidyAttr_PROPERTY); }
 
-    Bool IsHREF()          { return tidyAttrIsHREF( tattr() ); }
-    Bool IsSRC()           { return tidyAttrIsSRC( tattr() ); }
-    Bool IsID()            { return tidyAttrIsID( tattr() ); }
-    Bool IsNAME()          { return tidyAttrIsNAME( tattr() ); }
-    Bool IsSUMMARY()       { return tidyAttrIsSUMMARY( tattr() ); }
-    Bool IsALT()           { return tidyAttrIsALT( tattr() ); }
-    Bool IsLONGDESC()      { return tidyAttrIsLONGDESC( tattr() ); }
-    Bool IsUSEMAP()        { return tidyAttrIsUSEMAP( tattr() ); }
-    Bool IsISMAP()         { return tidyAttrIsISMAP( tattr() ); }
-    Bool IsLANGUAGE()      { return tidyAttrIsLANGUAGE( tattr() ); }
-    Bool IsTYPE()          { return tidyAttrIsTYPE( tattr() ); }
-    Bool IsVALUE()         { return tidyAttrIsVALUE( tattr() ); }
-    Bool IsCONTENT()       { return tidyAttrIsCONTENT( tattr() ); }
-    Bool IsTITLE()         { return tidyAttrIsTITLE( tattr() ); }
-    Bool IsXMLNS()         { return tidyAttrIsXMLNS( tattr() ); }
-    Bool IsDATAFLD()       { return tidyAttrIsDATAFLD( tattr() ); }
-    Bool IsWIDTH()         { return tidyAttrIsWIDTH( tattr() ); }
-    Bool IsHEIGHT()        { return tidyAttrIsHEIGHT( tattr() ); }
-    Bool IsFOR()           { return tidyAttrIsFOR( tattr() ); }
-    Bool IsSELECTED()      { return tidyAttrIsSELECTED( tattr() ); }
-    Bool IsCHECKED()       { return tidyAttrIsCHECKED( tattr() ); }
-    Bool IsLANG()          { return tidyAttrIsLANG( tattr() ); }
-    Bool IsTARGET()        { return tidyAttrIsTARGET( tattr() ); }
-    Bool IsHTTP_EQUIV()    { return tidyAttrIsHTTP_EQUIV( tattr() ); }
-    Bool IsREL()           { return tidyAttrIsREL( tattr() ); }
-    Bool IsOnMouseMove()   { return tidyAttrIsOnMOUSEMOVE( tattr() ); }
-    Bool IsOnMouseDown()   { return tidyAttrIsOnMOUSEDOWN( tattr() ); }
-    Bool IsOnMouseUp()     { return tidyAttrIsOnMOUSEUP( tattr() ); }
-    Bool IsOnClick()       { return tidyAttrIsOnCLICK( tattr() ); }
-    Bool IsOnMouseOver()   { return tidyAttrIsOnMOUSEOVER( tattr() ); }
-    Bool IsOnMouseOut()    { return tidyAttrIsOnMOUSEOUT( tattr() ); }
-    Bool IsOnKeyDown()     { return tidyAttrIsOnKEYDOWN( tattr() ); }
-    Bool IsOnKeyUp()       { return tidyAttrIsOnKEYUP( tattr() ); }
-    Bool IsOnKeyPress()    { return tidyAttrIsOnKEYPRESS( tattr() ); }
-    Bool IsOnFOCUS()       { return tidyAttrIsOnFOCUS( tattr() ); }
-    Bool IsOnBLUR()        { return tidyAttrIsOnBLUR( tattr() ); }
-    Bool IsBGCOLOR()       { return tidyAttrIsBGCOLOR( tattr() ); }
-    Bool IsLINK()          { return tidyAttrIsLINK( tattr() ); }
-    Bool IsALINK()         { return tidyAttrIsALINK( tattr() ); }
-    Bool IsVLINK()         { return tidyAttrIsVLINK( tattr() ); }
-    Bool IsTEXT()          { return tidyAttrIsTEXT( tattr() ); }
-    Bool IsSTYLE()         { return tidyAttrIsSTYLE( tattr() ); }
-    Bool IsABBR()          { return tidyAttrIsABBR( tattr() ); }
-    Bool IsCOLSPAN()       { return tidyAttrIsCOLSPAN( tattr() ); }
-    Bool IsROWSPAN()       { return tidyAttrIsROWSPAN( tattr() ); }
+    Bool IsHREF()          { return_(tidyAttrGetId( tattr() ) == TidyAttr_HREF); }
+    Bool IsSRC()           { return_(tidyAttrGetId( tattr() ) == TidyAttr_SRC); }
+    Bool IsID()            { return_(tidyAttrGetId( tattr() ) == TidyAttr_ID); }
+    Bool IsNAME()          { return_(tidyAttrGetId( tattr() ) == TidyAttr_NAME); }
+    Bool IsSUMMARY()       { return_(tidyAttrGetId( tattr() ) == TidyAttr_SUMMARY); }
+    Bool IsALT()           { return_(tidyAttrGetId( tattr() ) == TidyAttr_ALT); }
+    Bool IsLONGDESC()      { return_(tidyAttrGetId( tattr() ) == TidyAttr_LONGDESC); }
+    Bool IsUSEMAP()        { return_(tidyAttrGetId( tattr() ) == TidyAttr_USEMAP); }
+    Bool IsISMAP()         { return_(tidyAttrGetId( tattr() ) == TidyAttr_ISMAP); }
+    Bool IsLANGUAGE()      { return_(tidyAttrGetId( tattr() ) == TidyAttr_LANGUAGE); }
+    Bool IsTYPE()          { return_(tidyAttrGetId( tattr() ) == TidyAttr_TYPE); }
+    Bool IsVALUE()         { return_(tidyAttrGetId( tattr() ) == TidyAttr_VALUE); }
+    Bool IsCONTENT()       { return_(tidyAttrGetId( tattr() ) == TidyAttr_CONTENT); }
+    Bool IsTITLE()         { return_(tidyAttrGetId( tattr() ) == TidyAttr_TITLE); }
+    Bool IsXMLNS()         { return_(tidyAttrGetId( tattr() ) == TidyAttr_XMLNS); }
+    Bool IsDATAFLD()       { return_(tidyAttrGetId( tattr() ) == TidyAttr_DATAFLD); }
+    Bool IsWIDTH()         { return_(tidyAttrGetId( tattr() ) == TidyAttr_WIDTH); }
+    Bool IsHEIGHT()        { return_(tidyAttrGetId( tattr() ) == TidyAttr_HEIGHT); }
+    Bool IsFOR()           { return_(tidyAttrGetId( tattr() ) == TidyAttr_FOR); }
+    Bool IsSELECTED()      { return_(tidyAttrGetId( tattr() ) == TidyAttr_SELECTED); }
+    Bool IsCHECKED()       { return_(tidyAttrGetId( tattr() ) == TidyAttr_CHECKED); }
+    Bool IsLANG()          { return_(tidyAttrGetId( tattr() ) == TidyAttr_LANG); }
+    Bool IsTARGET()        { return_(tidyAttrGetId( tattr() ) == TidyAttr_TARGET); }
+    Bool IsHTTP_EQUIV()    { return_(tidyAttrGetId( tattr() ) == TidyAttr_HTTP_EQUIV); }
+    Bool IsREL()           { return_(tidyAttrGetId( tattr() ) == TidyAttr_REL); }
+    Bool IsOnMouseMove()   { return_(tidyAttrGetId( tattr() ) == TidyAttr_OnMOUSEMOVE); }
+    Bool IsOnMouseDown()   { return_(tidyAttrGetId( tattr() ) == TidyAttr_OnMOUSEDOWN); }
+    Bool IsOnMouseUp()     { return_(tidyAttrGetId( tattr() ) == TidyAttr_OnMOUSEUP); }
+    Bool IsOnClick()       { return_(tidyAttrGetId( tattr() ) == TidyAttr_OnCLICK); }
+    Bool IsOnMouseOver()   { return_(tidyAttrGetId( tattr() ) == TidyAttr_OnMOUSEOVER); }
+    Bool IsOnMouseOut()    { return_(tidyAttrGetId( tattr() ) == TidyAttr_OnMOUSEOUT); }
+    Bool IsOnKeyDown()     { return_(tidyAttrGetId( tattr() ) == TidyAttr_OnKEYDOWN); }
+    Bool IsOnKeyUp()       { return_(tidyAttrGetId( tattr() ) == TidyAttr_OnKEYUP); }
+    Bool IsOnKeyPress()    { return_(tidyAttrGetId( tattr() ) == TidyAttr_OnKEYPRESS); }
+    Bool IsOnFOCUS()       { return_(tidyAttrGetId( tattr() ) == TidyAttr_OnFOCUS); }
+    Bool IsOnBLUR()        { return_(tidyAttrGetId( tattr() ) == TidyAttr_OnBLUR); }
+    Bool IsBGCOLOR()       { return_(tidyAttrGetId( tattr() ) == TidyAttr_BGCOLOR); }
+    Bool IsLINK()          { return_(tidyAttrGetId( tattr() ) == TidyAttr_LINK); }
+    Bool IsALINK()         { return_(tidyAttrGetId( tattr() ) == TidyAttr_ALINK); }
+    Bool IsVLINK()         { return_(tidyAttrGetId( tattr() ) == TidyAttr_VLINK); }
+    Bool IsTEXT()          { return_(tidyAttrGetId( tattr() ) == TidyAttr_TEXT); }
+    Bool IsSTYLE()         { return_(tidyAttrGetId( tattr() ) == TidyAttr_STYLE); }
+    Bool IsABBR()          { return_(tidyAttrGetId( tattr() ) == TidyAttr_ABBR); }
+    Bool IsCOLSPAN()       { return_(tidyAttrGetId( tattr() ) == TidyAttr_COLSPAN); }
+    Bool IsROWSPAN()       { return_(tidyAttrGetId( tattr() ) == TidyAttr_ROWSPAN); }
 
 protected:
     TidyAttr tattr()
