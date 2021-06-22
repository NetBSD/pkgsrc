# $NetBSD: options.mk,v 1.2 2021/06/22 08:29:36 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.slim
PKG_SUPPORTED_OPTIONS=	consolekit
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

#
# Consolekit support
#
.if !empty(PKG_OPTIONS:Mconsolekit)
.include "../../sysutils/consolekit/buildlink3.mk"
CMAKE_ARGS=	-DUSE_CONSOLEKIT:Bool=Yes
.else
CMAKE_ARGS=	-DUSE_CONSOLEKIT:Bool=No
.endif
