# $NetBSD: options.mk,v 1.1 2021/06/11 10:37:12 abs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.slim
PKG_SUPPORTED_OPTIONS=	consolekit
PKG_SUGGESTED_OPTIONS=	consolekit

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
