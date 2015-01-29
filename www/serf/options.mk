# $NetBSD: options.mk,v 1.1 2015/01/29 10:29:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.serf
PKG_SUPPORTED_OPTIONS=	gssapi
PKG_SUGGESTED_OPTIONS=	gssapi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
.include "../../mk/krb5.buildlink3.mk"
SCONS_ARGS+=		GSSAPI=${KRB5_CONFIG:Q}
.endif
