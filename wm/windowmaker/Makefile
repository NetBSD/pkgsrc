# $NetBSD: Makefile,v 1.1.1.1 2000/12/12 02:03:49 wiz Exp $

DISTNAME=		WindowMaker-0.62.1
PKGNAME=		windowmaker-0.62.1
CATEGORIES=		x11 wm
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/beta/srcs/ \
			ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/WindowMaker/beta/srcs/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.windowmaker.org/

BUILD_DEPENDS+=		${LOCALBASE}/bin/automake:../../devel/automake
BUILD_DEPENDS+=		gettextize:../../devel/gettext
DEPENDS+=		libproplist-0.10.*:../../devel/libproplist
DEPENDS+=		libungif-*:../../graphics/libungif
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff

USE_LIBTOOL=		YES
USE_LIBINTL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_X11BASE=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-usermenu \
			--with-nlsdir=${PREFIX}/share/locale \
			--with-incs-from="-I${LOCALBASE}/include" \
			--with-libs-from=" \
				-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib \
				-Wl,-R${X11BASE}/lib -L${X11BASE}/lib"
CONFIGURE_ENV+=		LINGUAS=yes

INSTALL_TARGET=		install-strip

.include "../../mk/bsd.prefs.mk"

# "egcs" has an optimizer problem on "arm32".
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "arm32"
CFLAGS=
.endif

# WINDOWMAKER_OPTIONS is a space-separated list of compile-time options
# to support.  Currently supported options:
#
#	kde		enable support for kde/kwm window manager hints
#	gnome		enable support for GNOME window manager hints
#	openlook	enable support for OPEN LOOK(tm) window manager hints
#	lite		remove Window Maker redundancies with KDE and GNOME
#
WINDOWMAKER_OPTIONS?=	gnome kde

BUILD_DEFS+=		WINDOWMAKER_OPTIONS

.for OPTION in ${WINDOWMAKER_OPTIONS}
CONFIGURE_ARGS+=	--enable-${OPTION}
.endfor

post-extract:
	${RM} -f ${WRKSRC}/WindowMaker/Defaults/WMState \
		 ${WRKSRC}/WindowMaker/Defaults/WMWindowAttributes \
		 ${WRKSRC}/WindowMaker/Defaults/WindowMaker
	for manfile in ${WRKSRC}/doc/*.1x; \
	do \
		${MV} $${manfile} `${ECHO} $${manfile} | ${SED} "s/1x$$/1/"`; \
	done;

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoconf; \
		${RM} doc/Makefile.in ; ${LOCALBASE}/bin/automake --no-force

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

.include "../../mk/bsd.pkg.mk"
