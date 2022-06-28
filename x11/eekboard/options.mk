# $NetBSD: options.mk,v 1.7 2022/06/28 11:40:47 nia Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.eekboard
PKG_SUPPORTED_OPTIONS=	vala xtest libcanberra
PKG_SUGGESTED_OPTIONS=	vala xtest

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	vala

.if !empty(PKG_OPTIONS:Mvala)
PLIST.vala=	yes
.include "../../lang/vala/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-vala=yes
.else
CONFIGURE_ARGS+=	--enable-vala=no
.endif

.if !empty(PKG_OPTIONS:Mxtest)
.include "../../x11/libXtst/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-xtest=yes
.else
CONFIGURE_ARGS+=	--enable-xtest=no
.endif

.if !empty(PKG_OPTIONS:Mlibcanberra)
.include "../../audio/libcanberra/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-libcanberra=yes
.else
CONFIGURE_ARGS+=	--enable-libcanberra=no
.endif
