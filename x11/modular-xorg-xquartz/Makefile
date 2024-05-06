# $NetBSD: Makefile,v 1.24 2024/05/06 08:40:33 jperkin Exp $

DISTNAME=	modular-xorg-xquartz-1.20.99.1.20210408
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=XQuartz/}
GITHUB_PROJECT=	xorg-server
GITHUB_TAG=	199f278a1b7570b1cb6e24b8bedb4d721b3c9938

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xquartz.org/
COMMENT=	X11 server for Mac OS X
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config autoconf automake autoreconf m4
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
DEPENDS+=		{xterm,mxterm}-[0-9]*:../../x11/xterm
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

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-xkb-output=${XKB_OUTPUT_DIR:Q}
CONFIGURE_ARGS+=	--with-fontrootdir=${PREFIX}/share/fonts/X11
CONFIGURE_ARGS+=	--with-default-font-path=${FONT_PATHS:ts,:Q}

CONFIGURE_ARGS+=	--with-builder-addr="tech-x11@NetBSD.org"

CONFIGURE_ARGS+=	--enable-xtrans-send-fds
CONFIGURE_ARGS+=	--enable-dri
CONFIGURE_ARGS+=	--enable-dri2
CONFIGURE_ARGS+=	--enable-dri3
CONFIGURE_ARGS+=	--enable-glx
CONFIGURE_ARGS+=	--enable-glamor
CONFIGURE_ARGS+=	--enable-ipv6

CONFIGURE_ARGS+=	--with-apple-applications-dir=${PREFIX}/Applications/Utilities

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1 FILE_MAN_SUFFIX=5
CONFIGURE_ENV+=		DRIVER_MAN_SUFFIX=4

TOOL_DEPENDS+=		tradcpp-[0-9]*:../../devel/tradcpp
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="${TOOLBASE}/bin/tradcpp -Uunix"

.include "../../security/nettle/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sha1=libnettle

MAKE_ENV+=		OSX_SDK_PATH=${XCODE_SDK_PATH}

MESSAGE_SUBST+=		PREFIX=${PREFIX}

CHECK_PORTABILITY_SKIP+=	test/scripts/*
CHECK_PORTABILITY_SKIP+=	hw/xquartz/bundle/*

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/font-util/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../wm/libAppleWM/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXfont2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../x11/libxshmfence/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
