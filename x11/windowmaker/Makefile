# $NetBSD: Makefile,v 1.18 1999/01/19 22:12:15 tron Exp $

DISTNAME=		WindowMaker-0.50.2
PKGNAME=		windowmaker-0.50.2
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/beta/srcs/ \
			ftp://ftp.windowmaker.org/pub/contrib/icons/
DISTFILES+=		${DISTNAME}${EXTRACT_SUFX}\
			WindowMaker-data.tar.gz

MAINTAINER=		lamj@stat.cmu.edu
HOMEPAGE=		http://windowmaker.org/

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		giflib-3.0:../../graphics/giflib
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		png-1.0.2:../../graphics/png
DEPENDS+=		tiff-3.4:../../graphics/tiff

CONFLICTS=		windowmaker-*

USE_LIBTOOL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-nlsdir=${PREFIX}/share/locale \
			--with-gfx-incs="-I${LOCALBASE}/include \
				-I${LOCALBASE}/include/giflib" \
			--with-gfx-libs=-L${LOCALBASE}/lib \
			--with-modelock
CONFIGURE_ENV+=		INSTALL="${INSTALL}" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_SCRIPT="${INSTALL_SCRIPT}"

PLIST_SRC=		${WRKDIR}/.PLIST_SRC_WM

.include "../../mk/bsd.prefs.mk"

# LINGUAS is a space-separated list of locales.  If it is defined, then
# i18n-support is compiled into Window Maker and the locales specified
# are installed.
#
.if defined(LINGUAS)
DEPENDS+=		gettext-0.10.35:../../devel/gettext
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" LINGUAS="${LINGUAS}"

# Enable multi-byte character support for languages that need it.
# Currently, those are: ja, ko
#
.for lang in ja ko
.if (${LINGUAS:M${lang}} != "")
ENABLE_WM_KANJI=	yes
.endif
.endfor
.if defined(ENABLE_WM_KANJI)
CONFIGURE_ARGS+=	--enable-kanji
.endif # ENABLE_WM_KANJI
.endif # LINGUAS

# WINDOWMAKER_OPTIONS is a space-separated list of compile-time options
# to support.  Currently supported options:
#
#	kde		KDE WM-compliance
#	lite		remove Window Maker redundancies with KDE
#	gnome		GNOME-compliance
#
# Default: not defined
#
.for option in ${WINDOWMAKER_OPTIONS}
CONFIGURE_ARGS+=	--enable-${option}
.endfor

pre-configure:
	@${ECHO} "To compile with i18n support, set the variable LINGUAS"
	@${ECHO} "to the list of locales to install."

post-install:
	(cd ${WRKDIR}/WindowMaker-data/pixmaps/ ; for i in * ; do \
	 ${INSTALL_DATA} "$$i" ${PREFIX}/share/WindowMaker/Pixmaps/ ; \
	 done )
	${INSTALL_DATA_DIR} ${PREFIX}/share/WindowMaker/Sounds
	${TOUCH} ${PREFIX}/share/WindowMaker/Sounds/.keep_me
	${INSTALL_DATA} ${WRKSRC}/README.GNOME ${PREFIX}/share/WindowMaker
	${INSTALL_DATA} ${WRKSRC}/README.KDE ${PREFIX}/share/WindowMaker
	@${CAT} ${PKGDIR}/PLIST.nolinguas >${PLIST_SRC}
.if defined(LINGUAS)
	@(for lang in ${LINGUAS}; do \
	    if [ -f ${WRKSRC}/po/$${lang}.mo ]; then \
		${ECHO} share/locale/$${lang}/LC_MESSAGES/WindowMaker.mo; \
	    fi; \
	    if [ -f ${WRKSRC}/WPrefs.app/po/$${lang}.mo ]; then \
		${ECHO} share/locale/$${lang}/LC_MESSAGES/WPrefs.mo; \
	    fi; \
	    ${ECHO} @dirrm share/locale/$${lang}/LC_MESSAGES; \
	    ${ECHO} @dirrm share/locale/$${lang}; \
	done) >>${PLIST_SRC}
.endif

.include "../../mk/bsd.pkg.mk"
