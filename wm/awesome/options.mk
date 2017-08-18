# $NetBSD: options.mk,v 1.2 2017/08/18 10:16:11 triaxx Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.awesome
PKG_SUPPORTED_OPTIONS=		dbus debug doc
PLIST_VARS+=			doc

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

###
### DBus support
###
.if !empty(PKG_OPTIONS:Mdbus)
CMAKE_ARGS+=	-DWITH_DBUS=ON
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_DBUS=OFF
.endif

###
### Debug support
###
.if !empty(PKG_OPTIONS:Mdebug)
.  include "../../devel/libexecinfo/buildlink3.mk"
.endif

###
### Doc support
###
.if !empty(PKG_OPTIONS:Mdoc)
CMAKE_ARGS+=	-DGENERATE_DOC=ON
BUILD_DEPENDS+=	${LUA_PKGPREFIX}-LDoc-[0-9]*:../../textproc/LDoc
PLIST.doc=	yes
.else
CMAKE_ARGS+=	-DGENERATE_DOC=OFF
.endif
