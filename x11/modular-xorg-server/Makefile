# $NetBSD: Makefile,v 1.69.2.1 2012/12/18 17:43:02 tron Exp $
#

DISTNAME=	xorg-server-1.6.5
PKGNAME=	modular-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=xserver/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Modular X11 server from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir
SPECIAL_PERMS+=		bin/Xorg ${SETUID_ROOT_PERMS}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	xorg-server.pc.in
SHLIBTOOL_OVERRIDE=	# empty

BUILD_DEFS+=		VARBASE
BUILD_DEFS_EFFECTS+=	XKB_OUTPUT_DIR

OWN_DIRS+=		${VARBASE}/log
OWN_DIRS+=		${XKB_OUTPUT_DIR}
XKB_OUTPUT_DIR?=	${VARBASE}/db/xkb # XXX sync with xkeyboard-config

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--with-xkb-output=${XKB_OUTPUT_DIR:Q}

.if !empty(USE_TOOLS:Mauto*)
BUILD_DEPENDS+=	xorg-util-macros>=1.1.5:../../devel/xorg-util-macros
.endif

DEPENDS+=	xkbcomp-[0-9]*:../../x11/xkbcomp
DEPENDS+=	xkeyboard-config-[0-9]*:../../x11/xkeyboard-config

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-release-version=${PKGNAME:Q}
CONFIGURE_ARGS+=	--with-vendor-name="The NetBSD Foundation"
CONFIGURE_ARGS+=	--with-vendor-name-short="pkgsrc"
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-builder-addr="tech-x11@NetBSD.org"
CONFIGURE_ARGS+=	--with-os-vendor="The NetBSD Foundation"
.endif
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--without-dtrace
.endif
.if ${OPSYS} == "FreeBSD"
CONFIGURE_ARGS+=	--without-dtrace
.endif
CONFIGURE_ARGS+=	--with-os-name=${MACHINE_PLATFORM:Q}
CONFIGURE_ARGS+=	--with-vendor-web="http://www.pkgsrc.org/"

CONFIGURE_ARGS+=	--enable-xorg

CONFIGURE_ARGS+=	--with-fontdir=${PREFIX}/share/fonts/X11

LEGACY_FONT_PATH=
DEFAULT_FONT_PATH=
.for f in misc TTF OTF Type1 100dpi 75dpi cyrillic
DEFAULT_FONT_PATH+=	${PREFIX}/share/fonts/X11/${f}
LEGACY_FONT_PATH+=	${PREFIX}/lib/X11/fonts/${f}
.endfor
FONT_PATH=		${DEFAULT_FONT_PATH} ${LEGACY_FONT_PATH}

CONFIGURE_ARGS+=	--with-default-font-path=${FONT_PATH:ts,:Q}

CONFIGURE_ARGS+=	--disable-config-hal
CONFIGURE_ARGS+=	--disable-dmx
CONFIGURE_ARGS+=	--disable-xprint
CONFIGURE_ARGS+=	--disable-xwin
CONFIGURE_ARGS+=	--disable-xephyr
CONFIGURE_ARGS+=	--disable-kdrive
CONFIGURE_ARGS+=	--disable-kdrive-vesa
CONFIGURE_ARGS+=	--disable-xfake
CONFIGURE_ARGS+=	--disable-xsdl
CONFIGURE_ARGS+=	--disable-xfbdev
CONFIGURE_ARGS+=	--disable-kbd_mode	# deprecated
CONFIGURE_ARGS+=	--disable-xorgcfg	# deprecated

CONFIGURE_ARGS+=	--with-int10=x86emu

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1 FILE_MAN_SUFFIX=5
CONFIGURE_ENV+=		DRIVER_MAN_SUFFIX=4

PLIST_VARS+=		sunos
PLIST_SUBST+=		SUNOS_ARCH=${SUNOS_ARCH}

.if ${OPSYS} == "SunOS"
PLIST.sunos=		yes
.  if ${MACHINE_ARCH} == "i386"
SUNOS_ARCH=		ia32
.  elif ${MACHINE_ARCH} == "amd64" || ${MACHINE_ARCH} == "x86_64"
SUNOS_ARCH=		amd64
.  elif ${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "sparc64"
SUNOS_ARCH=		sparcv8plus
.  endif
.endif

# Workaround for PR#41556.
# Avoid to use bsd_kqueue_apm, force to use bsd_apm instead.
.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		ac_cv_header_sys_event_h=no
.endif

INSTALLATION_DIRS+=	lib/xorg/modules/drivers lib/xorg/modules/input

BUILDLINK_API_DEPENDS.MesaLib+=		MesaLib>=7.1.0
BUILDLINK_API_DEPENDS.compositeproto+=	compositeproto>=0.4
BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=4.0
BUILDLINK_API_DEPENDS.glproto+=		glproto>=1.4.9
BUILDLINK_API_DEPENDS.inputproto+=	inputproto>=1.5
BUILDLINK_API_DEPENDS.kbproto+=		kbproto>=1.0.3
BUILDLINK_API_DEPENDS.pixman+=		pixman>=0.13.2
BUILDLINK_API_DEPENDS.randrproto+=	randrproto>=1.2.99.1
BUILDLINK_API_DEPENDS.renderproto+=	renderproto>=0.9.3
BUILDLINK_API_DEPENDS.xf86dgaproto+=	xf86dgaproto>=2.0.3
BUILDLINK_API_DEPENDS.xf86driproto+=	xf86driproto>=2.0.4

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
BUILD_DEPENDS+=		ucpp-[0-9]*:../../devel/ucpp
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="${PREFIX}/bin/ucpp -t -c90 -Uunix"
.elif empty(PKGSRC_COMPILER:Mgcc)
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="cc -E -Uunix -"
.endif

.include "options.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libpciaccess+=	libpciaccess>=0.11.0
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../x11/bigreqsproto/buildlink3.mk"
.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/damageproto/buildlink3.mk"
.include "../../x11/dri2proto/buildlink3.mk"
.include "../../x11/evieext/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXext+=	libXext>=1.1.1
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXfont/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libxkbui/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
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
