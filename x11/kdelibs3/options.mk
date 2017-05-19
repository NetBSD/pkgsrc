# $NetBSD: options.mk,v 1.4 2017/05/19 13:18:19 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdelibs
PKG_SUPPORTED_OPTIONS=	cups debug

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		cups
.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
PLIST.cups=		yes
.else
CONFIGURE_ARGS+=	--disable-cups
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CC+=			-ggdb
CXX+=			-ggdb
CONFIGURE_ARGS+=	--enable-debug=full
CONFIGURE_ENV+=		INSTALL_STRIP_FLAG=
INSTALL_UNSTRIPPED=	yes
.endif
