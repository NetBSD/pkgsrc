# $NetBSD: options.mk,v 1.2 2026/04/22 18:00:46 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.worker
PKG_SUPPORTED_OPTIONS=	avfs dbus lua inotify ssl xft2
PKG_SUGGESTED_OPTIONS=	avfs dbus ssl xft2

.include "../../mk/bsd.options.mk"

# AVFS backend
.if !empty(PKG_OPTIONS:Mavfs)
CONFIGURE_ARGS+=        --with-avfs
.  include "../../filesystems/avfs/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --without-avfs
.endif

# Xft support
.if !empty(PKG_OPTIONS:Mxft2)
CONFIGURE_ARGS+=	--enable-xft
.include	"../../x11/libXft/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

# Lua scripting
.if !empty(PKG_OPTIONS:Mlua)
CONFIGURE_ARGS+=	--enable-lua
.include	"../../lang/lua/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-lua
.endif

# DBUS device handling
.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=        --with-dbus
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --without-dbus
.endif

# Checksumming support
.if !empty(PKG_OPTIONS:Mssl)
.include	"../../security/openssl/buildlink3.mk"
.endif

# Inotify support
.if !empty(PKG_OPTIONS:Minotify)
CONFIGURE_ARGS+=	--enable-inotify
.  include	"../../devel/libinotify/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-inotify
.endif
