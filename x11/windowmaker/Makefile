# $NetBSD: Makefile,v 1.33 1999/08/18 09:16:40 agc Exp $

DISTNAME=		WindowMaker-0.60.0
PKGNAME=		windowmaker-0.60.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/beta/srcs/ \
			ftp://shadowmere.student.utwente.nl/pub/WindowMaker/ \
			ftp://ftp.univie.ac.at/systems/linux/linuxberg/files/x11/xwin/ \
			ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/WindowMaker/beta/srcs/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.windowmaker.org/

DEPENDS+=		libproplist-0.8.3:../../devel/libproplist
DEPENDS+=		giflib-3.0:../../graphics/giflib
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png-1.0.3:../../graphics/png
DEPENDS+=		tiff-3.4:../../graphics/tiff
DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_LIBTOOL=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-nlsdir=${PREFIX}/share/locale \
			--with-incs-from="-I${LOCALBASE}/include \
				-I${LOCALBASE}/include/giflib"
LDFLAGS+=		-L${LOCALBASE}/lib	# for libintl.a

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
BUILD_DEPENDS+=		gettext-0.10.35:../../devel/gettext
CONFIGURE_ARGS+=	--enable-modelock
CONFIGURE_ENV+=		LINGUAS="${LINGUAS}"
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
