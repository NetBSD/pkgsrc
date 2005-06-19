# $NetBSD: options.mk,v 1.3 2005/06/19 01:46:36 salo Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.screws
PKG_SUPPORTED_OPTIONS=	inet6 lua ssl
PKG_SUGGESTED_OPTIONS=	lua ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=	IPV6=1
.else
MAKE_ENV+=	IPV6=0
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
MAKE_ENV+=	INCORE_LUA=1
.else
MAKE_ENV+=	INCORE_LUA=0
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
MAKE_ENV+=	SSL=1
.else
MAKE_ENV+=	SSL=0
.endif
