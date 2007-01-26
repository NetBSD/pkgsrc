# $NetBSD: options.mk,v 1.1 2007/01/26 02:44:28 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdelibs
PKG_SUPPORTED_OPTIONS=	cups debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.include "../../print/cups/buildlink3.mk"
PLIST_SUBST+=		CUPS=
.else
CONFIGURE_ARGS+=	--disable-cups
PLIST_SUBST+=		CUPS="@comment "
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CC+=			-ggdb
CXX+=			-ggdb
CONFIGURE_ARGS+=	--enable-debug=full
CONFIGURE_ENV+=		INSTALL_STRIP_FLAG=
INSTALL_UNSTRIPPED=	yes
.endif
