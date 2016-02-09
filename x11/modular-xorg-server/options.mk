# $NetBSD: options.mk,v 1.14 2016/02/09 01:17:37 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.modular-xorg-server
PKG_SUPPORTED_OPTIONS=	dri inet6 debug dtrace
PKG_SUGGESTED_OPTIONS=	dri inet6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dri dtrace

.if !empty(PKG_OPTIONS:Mdri)
.include "../../graphics/libepoxy/buildlink3.mk"
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=11
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/dri2proto/buildlink3.mk"
.include "../../x11/dri3proto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxshmfence/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
PLIST.dri=		yes
CONFIGURE_ARGS+=	--enable-dri
CONFIGURE_ARGS+=	--enable-dri2
CONFIGURE_ARGS+=	--enable-dri3
CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--enable-aiglx
CONFIGURE_ARGS+=	--enable-glamor
.else
###
### XXX Perhaps we should allow for a built-in glx without dri enabled?
###
CONFIGURE_ARGS+=	--disable-dri
CONFIGURE_ARGS+=	--disable-glx
pre-build: disable-modesetting
.PHONY: disable-modesetting
disable-modesetting:
	(${ECHO} "all:"; ${ECHO} "install:") > ${WRKSRC}/hw/xfree86/drivers/modesetting/Makefile
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
CFLAGS+=		-ggdb
.endif

.if !empty(PKG_OPTIONS:Mdtrace)
PLIST.dtrace=		yes
CONFIGURE_ARGS+=	--with-dtrace
.else
CONFIGURE_ARGS+=	--without-dtrace
.endif
