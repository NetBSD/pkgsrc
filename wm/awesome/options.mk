# $NetBSD: options.mk,v 1.4 2024/08/25 06:19:17 wiz Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.awesome
PKG_SUPPORTED_OPTIONS=		dbus debug

.include "../../mk/bsd.options.mk"

###
### DBus support
###
.if !empty(PKG_OPTIONS:Mdbus)
CMAKE_CONFIGURE_ARGS+=	-DWITH_DBUS=ON
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_DBUS=OFF
.endif

###
### Debug support
###
.if !empty(PKG_OPTIONS:Mdebug)
.  include "../../devel/libexecinfo/buildlink3.mk"
.endif
