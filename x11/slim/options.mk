# $NetBSD: options.mk,v 1.4 2025/08/18 06:33:12 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.slim
PKG_SUPPORTED_OPTIONS=	consolekit
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

#
# Consolekit support
#
.if !empty(PKG_OPTIONS:Mconsolekit)
.include "../../sysutils/consolekit/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DUSE_CONSOLEKIT:Bool=Yes
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_CONSOLEKIT:Bool=No
.endif
