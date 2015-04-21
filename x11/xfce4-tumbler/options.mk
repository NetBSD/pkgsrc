# $NetBSD: options.mk,v 1.1 2015/04/21 08:56:45 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tumbler
PKG_SUPPORTED_OPTIONS=	jpeg ffmpegthumbnailer pdf odf
PKG_SUGGESTED_OPTIONS=	jpeg ffmpegthumbnailer pdf odf

PLIST_VARS+=	jpeg ffmpegthumbnailer pdf odf

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
PLIST.jpeg=	yes
.endif
.if !empty(PKG_OPTIONS:Mffmpegthumbnailer)
.include "../../multimedia/ffmpegthumbnailer/buildlink3.mk"
PLIST.ffmpegthumbnailer=	yes
.endif
.if !empty(PKG_OPTIONS:Mpdf)
.include "../../print/poppler-glib/buildlink3.mk"
PLIST.pdf=	yes
.endif
.if !empty(PKG_OPTIONS:Modf)
.include "../../devel/libgsf/buildlink3.mk"
PLIST.odf=	yes
.endif
