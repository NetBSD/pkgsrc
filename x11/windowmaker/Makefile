# $NetBSD: Makefile,v 1.42 2000/03/21 22:40:59 tron Exp $

DISTNAME=		WindowMaker-0.61.1
PKGNAME=		windowmaker-0.61.1
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/beta/srcs/ \
			ftp://shadowmere.student.utwente.nl/pub/WindowMaker/ \
			ftp://ftp.univie.ac.at/systems/linux/linuxberg/files/x11/xwin/ \
			ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/WindowMaker/beta/srcs/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.windowmaker.org/

DEPENDS+=		libproplist-0.9.*:../../devel/libproplist
DEPENDS+=		libungif-*:../../graphics/libungif
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png>=1.0.6:../../graphics/png
DEPENDS+=		tiff-*:../../graphics/tiff
DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_LIBTOOL=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-usermenu \
			--with-nlsdir=${PREFIX}/share/locale \
			--with-incs-from="-I${LOCALBASE}/include"

# The following ensures that `get-wraster-flags --ldflags' returns the
# correct linker flags.
#
CONFIGURE_ARGS+=	--with-libs-from=" \
				-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib \
				-Wl,-R${X11BASE}/lib -L${X11BASE}/lib"

# WINDOWMAKER_OPTIONS is a space-separated list of compile-time options
# to support.  Currently supported options:
#
#	kde		enable support for kde/kwm window manager hints
#	gnome		enable support for GNOME window manager hints
#	openlook	enable support for OPEN LOOK(tm) window manager hints
#	lite		remove Window Maker redundancies with KDE and GNOME
#
WINDOWMAKER_OPTIONS?=	gnome kde

PLIST_SRC=		${WRKDIR}/.PLIST_SRC_WM

BUILD_DEFS+=		WINDOWMAKER_OPTIONS

.include "../../mk/bsd.prefs.mk"

.for OPTION in ${WINDOWMAKER_OPTIONS}
CONFIGURE_ARGS+=	--enable-${OPTION}
.endfor

# LINGUAS is a space-separated list of locales.  If it is defined, then
# i18n-support is compiled into Window Maker and the locales specified
# are installed.
#
.if defined(LINGUAS)
BUILD_DEPENDS+=		gettext-0.10.*:../../devel/gettext
CONFIGURE_ARGS+=	--enable-modelock
CONFIGURE_ENV+=		LINGUAS="${LINGUAS}"
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib	# -lintl
.endif # LINGUAS

post-extract:
	${RM} -f ${WRKSRC}/WindowMaker/Defaults/WMState \
		 ${WRKSRC}/WindowMaker/Defaults/WMWindowAttributes \
		 ${WRKSRC}/WindowMaker/Defaults/WindowMaker

pre-configure:
.if !defined(LINGUAS)
	@${ECHO} "To compile with i18n support, set the variable LINGUAS"
	@${ECHO} "to the list of locales to install."
.else
	@${ECHO} "Compiling support for locales: ${LINGUAS}"
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/WindowMaker/SoundSets
	${INSTALL_DATA_DIR} ${PREFIX}/share/WindowMaker/Sounds
	${TOUCH} ${PREFIX}/share/WindowMaker/SoundSets/.keep_me
	${TOUCH} ${PREFIX}/share/WindowMaker/Sounds/.keep_me
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/WindowMaker
	${INSTALL_DATA} \
		${WRKSRC}/README \
		${WRKSRC}/README.GNOME \
		${WRKSRC}/README.KDE \
		${PREFIX}/share/doc/WindowMaker
	@${CAT} ${PKGDIR}/PLIST.nolinguas >${PLIST_SRC}
.if defined(LINGUAS)
	@(for lang in ${LINGUAS}; do \
	    if [ -f ${WRKSRC}/po/$${lang}.mo ]; then \
		${ECHO} share/locale/$${lang}/LC_MESSAGES/WindowMaker.mo; \
	    fi; \
	    if [ -f ${WRKSRC}/WPrefs.app/po/$${lang}.mo ]; then \
		${ECHO} share/locale/$${lang}/LC_MESSAGES/WPrefs.mo; \
	    fi; \
	done) >>${PLIST_SRC}
.endif

.include "../../mk/bsd.pkg.mk"
