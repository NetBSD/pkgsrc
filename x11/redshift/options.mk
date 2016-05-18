# $NetBSD: options.mk,v 1.1 2016/05/18 22:18:43 snj Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.redshift

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
