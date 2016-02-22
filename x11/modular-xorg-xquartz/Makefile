# $NetBSD: Makefile,v 1.5 2016/02/22 20:02:36 jperkin Exp $

DISTNAME=	xorg-server-1.17.2
PKGNAME=	${DISTNAME:S/xorg-server/modular-xorg-xquartz/}
CATEGORIES=	x11
MASTER_SITES=	http://www.x.org/releases/individual/xserver/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.x.org/releases/individual/xserver/
COMMENT=	X11 server for Mac OS X
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++ objc

ONLY_FOR_PLATFORM=	Darwin-*-*

BUILD_DEFS+=		VARBASE
BUILD_DEFS_EFFECTS+=	XKB_OUTPUT_DIR

OWN_DIRS+=		${VARBASE}/log
OWN_DIRS+=		${XKB_OUTPUT_DIR}
XKB_OUTPUT_DIR?=	${VARBASE}/db/xkb # XXX sync with xkeyboard-config

DEPENDS+=		xkbcomp-[0-9]*:../../x11/xkbcomp
DEPENDS+=		xkeyboard-config-[0-9]*:../../x11/xkeyboard-config

# Needed by X11.app:
DEPENDS+=		quartz-wm-[0-9]*:../../wm/quartz-wm
DEPENDS+=		xterm-[0-9]*:../../x11/xterm
DEPENDS+=		xinit-[0-9]*:../../x11/xinit

LEGACY_FONT_PATHS=
DEFAULT_FONT_PATHS=
.for f in misc TTF OTF Type1 100dpi 75dpi cyrillic
DEFAULT_FONT_PATHS+=	${PREFIX}/share/fonts/X11/${f}
LEGACY_FONT_PATHS+=	${PREFIX}/lib/X11/fonts/${f}
.endfor
FONT_PATHS=		${DEFAULT_FONT_PATHS} ${LEGACY_FONT_PATHS}

CONFIGURE_ARGS+=	--enable-xquartz
CONFIGURE_ARGS+=	--disable-xorg
CONFIGURE_ARGS+=	--disable-xephyr
CONFIGURE_ARGS+=	--disable-kdrive
CONFIGURE_ARGS+=	--disable-config-hal
CONFIGURE_ARGS+=	--disable-dmx
CONFIGURE_ARGS+=	--disable-xwin
CONFIGURE_ARGS+=	--disable-xfake
CONFIGURE_ARGS+=	--disable-xfbdev

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-xkb-output=${XKB_OUTPUT_DIR:Q}
CONFIGURE_ARGS+=	--with-fontrootdir=${PREFIX}/share/fonts/X11
CONFIGURE_ARGS+=	--with-default-font-path=${FONT_PATHS:ts,:Q}

CONFIGURE_ARGS+=	--with-builder-addr="tech-x11@NetBSD.org"
CONFIGURE_ARGS+=	--with-os-vendor="The NetBSD Foundation"
CONFIGURE_ARGS+=	--with-os-name=${MACHINE_PLATFORM:Q}

CONFIGURE_ARGS+=	--enable-xtrans-send-fds
CONFIGURE_ARGS+=	--enable-dri
CONFIGURE_ARGS+=	--enable-dri2
CONFIGURE_ARGS+=	--enable-dri3
CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--enable-aiglx
CONFIGURE_ARGS+=	--enable-glamor
CONFIGURE_ARGS+=	--enable-ipv6

CONFIGURE_ARGS+=	--with-apple-applications-dir=${PREFIX}/Applications/Utilities

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1 FILE_MAN_SUFFIX=5
CONFIGURE_ENV+=		DRIVER_MAN_SUFFIX=4

BUILD_DEPENDS+=		tradcpp-[0-9]*:../../devel/tradcpp
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="${PREFIX}/bin/tradcpp -Uunix"

.include "../../security/nettle/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sha1=libnettle

.if exists(/usr/bin/xcrun)
MY_XCODE_SDK_PATH!=	/usr/bin/xcrun --sdk macosx${OSX_VERSION} --show-sdk-path
MAKE_ENV+=		OSX_SDK_PATH=${MY_XCODE_SDK_PATH}
.endif

MESSAGE_SUBST+=		PREFIX=${PREFIX}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../wm/libAppleWM/buildlink3.mk"
.include "../../wm/applewmproto/buildlink3.mk"
.include "../../x11/bigreqsproto/buildlink3.mk"
.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/damageproto/buildlink3.mk"
.include "../../x11/evieext/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXfont/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libxkbui/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/presentproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/recordproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/resourceproto/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"
.include "../../x11/trapproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xcmiscproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xf86bigfontproto/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../x11/xf86miscproto/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/dri2proto/buildlink3.mk"
.include "../../x11/dri3proto/buildlink3.mk"
.include "../../x11/libxshmfence/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
