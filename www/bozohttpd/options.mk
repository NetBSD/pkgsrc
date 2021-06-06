# $NetBSD: options.mk,v 1.4 2021/06/06 13:38:43 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bozohttpd
PKG_SUPPORTED_OPTIONS=	lua ssl
PKG_SUGGESTED_OPTIONS=	lua ssl

.include "../../mk/bsd.options.mk"

###
### Support for Lua
###
.if !empty(PKG_OPTIONS:Mlua)
.  include "../../lang/lua/buildlink3.mk"
MAKE_FLAGS+=	EXTRALIBS="-llua"
.else
BOZO_CFLAGS+=	-DNO_LUA_SUPPORT
.endif

###
### Support for SSL
###
.if !empty(PKG_OPTIONS:Mssl)
CPPFLAGS+=	-DDO_HTPASSWD
.  include "../../security/openssl/buildlink3.mk"
.else
BOZO_CFLAGS+=	-DNO_SSL_SUPPORT
MAKE_FLAGS+=	CRYPTOLIBS=""
.endif
