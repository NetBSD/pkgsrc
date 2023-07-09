# $NetBSD: options.mk,v 1.1 2023/07/09 16:49:33 pho Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xf86-video-vmware
PKG_SUPPORTED_OPTIONS=	xatracker
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.prefs.mk"

# libudev is a Systemd thing, which only makes sense on Linux.
.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	udev
PKG_SUGGESTED_OPTIONS+=	udev
.endif

# xatracker is optionally provided by MesaLib. If X11 is a modular one
# we're sure it's available. Otherwise we don't know.
.if ${X11_TYPE} == "modular"
PKG_SUGGESTED_OPTIONS+=	xatracker
.endif

.include "../../mk/bsd.options.mk"

###
### udev support
###
.if !empty(PKG_OPTIONS:Mudev)
.  include "../../sysutils/libudev/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libudev
.else
CONFIGURE_ARGS+=	--without-libudev
.endif

###
### xatracker support
###
.if !empty(PKG_OPTIONS:Mxatracker)
CFLAGS+=	-fPIC
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=11
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../lang/libLLVM/buildlink3.mk"
.else
pre-configure:
	find ${BUILDLINK_DIR} -name xatracker.pc -delete
.endif
