# $NetBSD: Makefile,v 1.30 2002/11/21 16:08:49 tron Exp $

VERS=			0.80.2
DISTNAME=		WindowMaker-${VERS}
PKGNAME=		windowmaker-${VERS}
# PKGREVISION=		1
CATEGORIES=		x11 wm
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/source/release/ \
			ftp://ftp.ics.es.osaka-u.ac.jp/mirrors/WindowMaker/source/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.windowmaker.org/
COMMENT=		GNUStep-compliant NEXTSTEP(tm) window manager clone

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-usermenu \
			--with-nlsdir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ENV+=		LINGUAS=yes
CONFIGURE_ENV+=		CPP_PATH="${CPP}"

INSTALL_TARGET=		install-strip

.include "../../mk/bsd.prefs.mk"

# WINDOWMAKER_OPTIONS is a space-separated list of compile-time options
# to support.  Currently supported options:
#
#	kde		enable support for kde/kwm window manager hints
#	gnome		enable support for GNOME window manager hints
#	openlook	enable support for OPEN LOOK(tm) window manager hints
#	lite		remove Window Maker redundancies with KDE and GNOME
#			(this option is broke in WindowMaker 0.65.x)
#
WINDOWMAKER_OPTIONS?=	gnome kde openlook

BUILD_DEFS+=		WINDOWMAKER_OPTIONS

.for OPTION in ${WINDOWMAKER_OPTIONS}
CONFIGURE_ARGS+=	--enable-${OPTION}
.endfor

post-extract:
	${RM} -f ${WRKSRC}/WindowMaker/Defaults/WMState \
		 ${WRKSRC}/WindowMaker/Defaults/WMWindowAttributes \
		 ${WRKSRC}/WindowMaker/Defaults/WindowMaker \
		 ${WRKSRC}/po/zh_TW.Big5.po
	for manfile in ${WRKSRC}/doc/*.1x ${WRKSRC}/doc/*/*.1x; \
	do \
		${MV} $${manfile} `${ECHO} $${manfile} | ${SED} "s/1x$$/1/"`; \
	done;
	cd ${WRKSRC} && \
	for f in WINGs/wapplication.c WindowMaker/Defaults/WindowMaker.in \
		WPrefs.app/Paths.c WindowMaker/menu* WindowMaker/plmenu*; do \
		${SED} "s|/usr/local|${PREFIX}|g" $$f > $$f.new && \
		${MV} $$f.new $$f; \
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/WindowMaker/SoundSets
	${INSTALL_DATA_DIR} ${PREFIX}/share/WindowMaker/Sounds
	${TOUCH} ${PREFIX}/share/WindowMaker/SoundSets/.directory
	${TOUCH} ${PREFIX}/share/WindowMaker/Sounds/.directory
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/WindowMaker
	cd ${WRKSRC}; ${INSTALL_DATA} \
		README README.GNOME README.KDE README.definable-cursor \
		FAQ FAQ.I18N \
		${PREFIX}/share/doc/WindowMaker

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/hermes/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

# "egcs" has an optimizer problem on "arm32".
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "arm32"
CFLAGS:=	-O0
.endif
