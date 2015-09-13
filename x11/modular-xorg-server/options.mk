# $NetBSD: options.mk,v 1.12 2015/09/13 04:59:35 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.modular-xorg-server
PKG_SUPPORTED_OPTIONS=	dri inet6 debug dtrace
PKG_SUGGESTED_OPTIONS=	dri inet6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		dri dri3 dtrace glamor

.if !empty(PKG_OPTIONS:Mdri)
.include "../../graphics/libepoxy/buildlink3.mk"
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=10
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/dri2proto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
PLIST.dri=		yes
CONFIGURE_ARGS+=	--enable-dri
CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--enable-aiglx
.  if ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
PLIST.glamor=		yes
CONFIGURE_ARGS+=	--enable-glamor
.include "../../x11/libxshmfence/buildlink3.mk"
.  endif
# Linux supports dri3
.  if ${OPSYS} == "Linux"
PLIST.dri3=		yes
.include "../../x11/dri3proto/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dri3
.  else
CONFIGURE_ARGS+=	--disable-dri3
.  endif
.else
###
### XXX Perhaps we should allow for a built-in glx without dri enabled?
###
CONFIGURE_ARGS+=	--disable-dri
CONFIGURE_ARGS+=	--disable-glx
pre-build: disable-modesetting
.PHONY: disable-modesetting
disable-modesetting:
	(echo "all:"; echo "install:") > ${WRKSRC}/hw/xfree86/drivers/modesetting/Makefile
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
