# $NetBSD: Makefile,v 1.1.1.1 2000/04/28 17:18:21 drochner Exp $
#

DISTNAME=	qt-x11-2.1.0
PKGNAME=	qt21-2.1.0
WRKSRC=		${WRKDIR}/qt-2.1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.troll.no/qt/source/ \
		ftp://ftp.fu-berlin.de/unix/X11/gui/Qt/source/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.troll.no/products/qt.html

DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	png-*:../../graphics/png
DEPENDS+=	jpeg-*:../../graphics/jpeg

NOT_FOR_PLATFORM=    *-*-alpha	# builds, but programs linked to qt crash

HAS_CONFIGURE=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ENV+=		QTDIR=${WRKSRC}
CONFIGURE_ARGS+=	-static -sm -system-zlib \
			-system-libpng -system-jpeg \
			-I${LOCALBASE}/include -L${LOCALBASE}/lib \

MAKE_ENV+=	QTDIR=${WRKSRC}
ALL_TARGET=	src

.include "../../mk/bsd.prefs.mk"

.if defined(USE_GIF)
CONFIGURE_ARGS+=	-gif
.endif

.if ${OPSYS} == "SunOS"
DEPENDS+=	egcs-1.1.2:../../lang/egcs
CXX=		${LOCALBASE}/egcs/bin/g++
.endif

QTPREFIX=	${PREFIX}/qt21

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/lib
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqt.la ${QTPREFIX}/lib
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
	${RM} -f ${WRKSRC}/include/qt_mac.h ${WRKSRC}/include/qt_windows.h
	${INSTALL_DATA} ${WRKSRC}/include/* ${QTPREFIX}/include
	${INSTALL_DATA_DIR} ${QTPREFIX}/doc
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.QT ${QTPREFIX}/doc
	${INSTALL_DATA_DIR} ${QTPREFIX}/doc/man
	${INSTALL_MAN_DIR}  ${QTPREFIX}/doc/man/man3
	@cd ${WRKSRC}/doc/man/man3; PAGES="`ls -1 | ${SED} -e 's,3qt$$,3,'`"; \
	(for PAGE in $$PAGES; do \
	    ${ECHO} installing ${QTPREFIX}/doc/man/man3/$${PAGE}; \
	    set - X `head -1 $${PAGE}qt`; \
	    if [ $$# -eq 3 ] && [ "$$2" = .so ]; then \
		${LN} -fs `basename $$3 | ${SED} s/qt$$//` \
		  ${QTPREFIX}/doc/man/man3/$${PAGE}; \
	    else \
		${INSTALL_MAN} $${PAGE}qt ${QTPREFIX}/doc/man/man3/$${PAGE}; \
	    fi; \
	 done)
	${INSTALL_DATA_DIR} ${QTPREFIX}/doc/html
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${QTPREFIX}/doc/html

.include "../../mk/bsd.pkg.mk"
