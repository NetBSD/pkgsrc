# $NetBSD: options.mk,v 1.1 2020/08/09 17:25:37 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.luakit
PKG_SUPPORTED_OPTIONS=		luajit
.include "../../lang/LuaJIT2/platform.mk"
.if !empty(PLATFORM_SUPPORTS_LUAJIT:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS=		luajit
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mluajit)
MAKE_FLAGS+=	USE_LUAJIT=1
NOT_PAX_MPROTECT_SAFE+=	bin/luakit
.  include "../../lang/LuaJIT2/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_LUAJIT=0
.  include "../../lang/lua51/buildlink3.mk"
.endif
