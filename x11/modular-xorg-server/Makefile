# $NetBSD: Makefile,v 1.20 2007/10/29 16:04:53 shannonjr Exp $

DISTNAME=	xorg-server-1.3.0.0
PKGNAME=	modular-${DISTNAME}
CATEGORIES=	local
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/xserver/
EXTRACT_SUFX=	.tar.bz2

SPECIAL_PERMS+=	bin/Xorg ${SETUID_ROOT_PERMS}
PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	shannonjr@NetBSD.org
COMMENT=	Xorg X11 Server from modular X.org X11

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE+=	xorg-server.pc.in
USE_TOOLS+=		pkg-config
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

PKG_SUPPORTED_OPTIONS=	xglx
PKG_OPTIONS_VAR=	PKG_OPTIONS.xorg-server
PKG_OPTIONS_LEGACY_OPTS=glx:dri
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxglx)
CONFIGURE_ENV+=		GLX_DEFINES=${GLX_DEFINES:M*:Q}
PLIST_SUBST+=		USE_DRI=""
CONFIGURE_ARGS+=	--enable-xglx
CONFIGURE_ARGS+=	--enable-xgl
CONFIGURE_ARGS+=	--enable-xkb
CONFIGURE_ARGS+=	--disable-dri
CONFIGURE_ARGS+=	--disable-kdriveserver
CONFIGURE_ARGS+=	--enable-dlopen
AUTOCONF_REQD=		2.61
USE_TOOLS+=		autoconf
.endif

CONFIGURE_ENV+=	APP_MAN_SUFFIX=1 FILE_MAN_SUFFIX=5

BUILD_DEFS+=		VARBASE

# -wip
#DEPENDS+=		xkeyboard-config-[0-9]*:../../x11/xkeyboard-config
DEPENDS+=		xkbdata-[0-9]*:../../x11/xkbdata

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4.0
BUILDLINK_API_DEPENDS.kbproto+=		kbproto>=1.0.3
BUILDLINK_API_DEPENDS.randrproto+=	randrproto>=1.2.1


post-extract:
	${CP} ${FILESDIR}/modeline2c.awk ${WRKSRC}/hw/xfree86/common
.if !empty(PKG_OPTIONS:Mdri)
	${LN} -s ${MESA_SRC:Q}/include/GL ${WRKSRC:Q}/GL/glx/GL
.endif

.if !empty(PKG_OPTIONS:Mxglx)
pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../x11/bigreqsproto/buildlink3.mk"
.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/damageproto/buildlink3.mk"
.include "../../x11/evieext/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXfont/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libxkbui/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/recordproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/resourceproto/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"
.include "../../x11/trapproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xcmiscproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86bigfontproto/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
