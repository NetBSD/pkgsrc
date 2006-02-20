# $NetBSD: options.mk,v 1.1.1.1 2006/02/20 12:08:11 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qt4
PKG_SUPPORTED_OPTIONS=	cups debug

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/cups/buildlink3.mk"
CONFIGURE_ARGS+=	-cups
.else
CONFIGURE_ARGS+=	-no-cups
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CC+=			-ggdb
CXX+=			-ggdb
CONFIGURE_ARGS+=	--debug
INSTALL_UNSTRIPPED=	yes
.endif
