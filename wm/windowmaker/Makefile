# $NetBSD: Makefile,v 1.97 2013/02/16 11:18:02 wiz Exp $

DISTNAME=	WindowMaker-0.92.0
PKGNAME=	${DISTNAME:S/WindowMaker/windowmaker/}
PKGREVISION=	21
CATEGORIES=	x11 wm windowmaker
MASTER_SITES=	http://windowmaker.info/pub/source/release/ \
	ftp://ftp.dti.ad.jp/pub/X/WindowMaker/source/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.windowmaker.info/
COMMENT=	GNUStep-compliant NEXTSTEP(tm) window manager clone

BROKEN_GETTEXT_DETECTION=	yes

USE_TOOLS+=		msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-usermenu
CONFIGURE_ARGS+=	--enable-xinerama
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-gnustepdir=${PREFIX}/share/GNUstep
CONFIGURE_ARGS+=	--with-nlsdir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ENV+=		LINGUAS=yes
CONFIGURE_ENV+=		CPP_PATH=${CPP:Q}
USE_TOOLS+=		perl:run
REPLACE_PERL+=		util/wkdemenu.pl

INSTALLATION_DIRS=	share/WindowMaker/SoundSets
INSTALLATION_DIRS+=	share/WindowMaker/Sounds
INSTALLATION_DIRS+=	share/doc/WindowMaker

.include "../../mk/compiler.mk"

.if !empty(MACHINE_PLATFORM:MSunOS-5.11-*)
CONFIGURE_ENV+=		ac_cv_lib_Xext_XineramaGetInfo=no
.endif

.if ${MACHINE_ARCH} != "i386"
CONFIGURE_ENV+=		ac_cv_c_inline_asm=no
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	3.0
.endif

PKG_SYSCONFSUBDIR=	WindowMaker
EGDIR=			${PREFIX}/share/examples/WindowMaker
CONF_FILES=
.for f in WMGLOBAL WMRootMenu WMState WMWindowAttributes WindowMaker
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# WINDOWMAKER_OPTIONS is a space-separated list of compile-time options
# to support.  Currently supported options:
#
#	kde		enable support for kde/kwm window manager hints
#	gnome		enable support for GNOME window manager hints
#	openlook	enable support for OPEN LOOK(tm) window manager hints
#	vdesktop	enable support for virtual desktop.

WINDOWMAKER_OPTIONS?=	gnome kde openlook vdesktop

BUILD_DEFS+=		WINDOWMAKER_OPTIONS

.for option in ${WINDOWMAKER_OPTIONS}
CONFIGURE_ARGS+=	--enable-${option}
.endfor

post-extract:
	${RM} -f ${WRKSRC}/WindowMaker/Defaults/WMState \
		 ${WRKSRC}/WindowMaker/Defaults/WMWindowAttributes \
		 ${WRKSRC}/WindowMaker/Defaults/WindowMaker \
		 ${WRKSRC}/po/zh_TW.Big5.po
	set -e; \
	for manfile in ${WRKSRC}/doc/*.1x ${WRKSRC}/doc/*/*.1x; \
	do \
		${MV} "$$manfile" `${ECHO} "$$manfile" | ${SED} "s/1x$$/1/"`; \
	done;
	set -e; \
	cd ${WRKSRC} && \
	for f in WINGs/wapplication.c WindowMaker/Defaults/WindowMaker.in \
		WPrefs.app/Paths.c WindowMaker/menu* WindowMaker/plmenu*; do \
		${SED}	-e "s|/usr/local|${PREFIX}|g" \
			-e "s|${PREFIX}/GNUstep|${PREFIX}/share/GNUstep|g" \
			"$$f" > "$$f".new && \
		${MV} "$$f".new "$$f"; \
	done

post-install:
	${TOUCH} ${DESTDIR}${PREFIX}/share/WindowMaker/SoundSets/.directory
	${TOUCH} ${DESTDIR}${PREFIX}/share/WindowMaker/Sounds/.directory
	cd ${WRKSRC} && \
	${INSTALL_DATA} \
		README README.definable-cursor FAQ FAQ.I18N \
		${DESTDIR}${PREFIX}/share/doc/WindowMaker

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
