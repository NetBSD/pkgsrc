<?xml version="1.0"?>

<!-- $NetBSD: index.xsl,v 1.1.1.1 2001/04/15 02:56:38 jwise Exp $ -->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="page">
<html>
 <head>
  <title><xsl:value-of select="@title" /></title>
 </head>
 <body bgcolor="#ADCFD4">

 <p><br /></p>

  <table border="0" width="60%" bgcolor="#000000" cellspacing="0" cellpadding="0" align="center">
   <tr>
    <td width="80%">
     <table border="0" width="100%" cellpadding="4">
      <tr>
       <td width="80%" bgcolor="#c0c0c0" align="right">
	<br />
        <h1><big><xsl:value-of select="@title" /></big></h1>
       </td>
      </tr>
      <tr>
       <td width="100%" bgcolor="#ffffff" align="left">
        <xsl:apply-templates/>
       </td>
      </tr>
      <tr>
       <td width="100%" bgcolor="#ffffff" align="left">
        <img align="right" src="sitedrivenby.gif" alt="Site Driven by NetBSD!" />
       </td>
      </tr>
     </table>
    </td>
   </tr>
  </table>
 </body>
</html>
</xsl:template>

<xsl:template match="pre|b|i|p|a|ul|li|img|dl|dt|dd">
 <xsl:copy-of select="."/>
</xsl:template>

</xsl:stylesheet>
