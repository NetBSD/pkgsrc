# $NetBSD: Makefile,v 1.31 2000/04/05 15:22:42 dmcmahill Exp $
#

DISTNAME=	qt-2.0.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.troll.no/qt/source/ \
		ftp://ftp.fu-berlin.de/unix/X11/gui/Qt/source/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.troll.no/products/qt.html

DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	png-*:../../graphics/png

HAS_CONFIGURE=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ENV+=		QTDIR=${WRKSRC}
CONFIGURE_ARGS+=	-static -sm -system-zlib -system-libpng \
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

QTPREFIX=	${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqt.la ${QTPREFIX}/lib
	${INSTALL_DATA_DIR} ${QTPREFIX}/include/qt
	${INSTALL_DATA} ${WRKSRC}/include/* ${QTPREFIX}/include/qt
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${QTPREFIX}/man/man1
	@cd ${WRKSRC}/man/man3; PAGES="`ls -1 | ${SED} -e 's,3qt$$,3,'`"; \
	(for PAGE in $$PAGES; do \
	    ${ECHO} installing ${QTPREFIX}/man/man3/$${PAGE}; \
	    set - X `head -1 $${PAGE}qt`; \
	    if [ $$# -eq 3 ] && [ "$$2" = .so ]; then \
		${LN} -fs `basename $$3 | ${SED} s/qt$$//` \
		  ${QTPREFIX}/man/man3/$${PAGE}; \
	    else \
		${INSTALL_MAN} $${PAGE}qt ${QTPREFIX}/man/man3/$${PAGE}; \
	    fi; \
	 done)
	${INSTALL_DATA_DIR} ${QTPREFIX}/share/doc/qt
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.QT \
	  ${WRKSRC}/doc/* ${QTPREFIX}/share/doc/qt

.include "../../mk/bsd.pkg.mk"
