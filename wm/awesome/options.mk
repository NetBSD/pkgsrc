# $NetBSD: options.mk,v 1.3 2019/07/17 22:08:58 nia Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.awesome
PKG_SUPPORTED_OPTIONS=		dbus debug

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
