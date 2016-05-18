# $NetBSD: options.mk,v 1.2 2016/05/18 22:47:42 snj Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.redshift
PKG_SUPPORTED_OPTIONS=	geoclue

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" \
    || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || ${OPSYS} == "SunOS"
PKG_SUPPORTED_OPTIONS+=	libdrm
PKG_SUGGESTED_OPTIONS+=	libdrm

.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibdrm)
.include "../../x11/libdrm/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-drm
.else
CONFIGURE_ARGS+=	--disable-drm
.endif

.if !empty(PKG_OPTIONS:Mgeoclue)
.include "../../geography/geoclue/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-geoclue --disable-geoclue2
.endif
