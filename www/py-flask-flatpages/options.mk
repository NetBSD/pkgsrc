# $NetBSD: options.mk,v 1.2 2021/04/06 15:22:38 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-flask-flatpages
PKG_SUPPORTED_OPTIONS=	pygments
PKG_SUGGESTED_OPTIONS+=	pygments

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpygments)
PYTHON_VERSIONED_DEPENDENCIES=	pygments
.endif
