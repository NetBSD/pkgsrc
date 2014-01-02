# $NetBSD: options.mk,v 1.3 2014/01/02 09:02:22 mrg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bozohttpd
PKG_SUPPORTED_OPTIONS=	bozohttpd-do-htpasswd

.include "../../mk/bsd.options.mk"

###
### Support Apache's .htpasswd files.
###
.if !empty(PKG_OPTIONS:Mbozohttpd-do-htpasswd)
CPPFLAGS+=	-DDO_HTPASSWD
.endif

###
### Support for lua -- missing
###
