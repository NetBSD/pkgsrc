# $NetBSD: Makefile,v 1.21 1998/11/10 23:58:49 tron Exp $
#

DISTNAME=	qt-1.41
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.troll.no/qt/source/ \
		ftp://ftp.fu-berlin.de/unix/X11/gui/Qt/source/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.troll.no/products/qt.html

CONFLICTS=	qt-1.33 qt-1.40

USE_X11=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

MAKE_ENV=	QTDIR=${WRKSRC}
ALL_TARGET=	src

do-configure:
	@cd ${WRKSRC} && ${MAKE} QTDIR=${WRKSRC} netbsd-g++-static

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${PREFIX}/bin/
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqt.la ${PREFIX}/lib/
	${INSTALL_DATA_DIR} ${PREFIX}/include/qt
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/qt/
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/man/man1/
	@cd ${WRKSRC}/man/man3; PAGES="`ls -1 | ${SED} -e 's,3qt$$,3,'`"; \
	(for PAGE in $$PAGES; do \
	    ${ECHO} installing ${PREFIX}/man/man3/$${PAGE}; \
	    set - X `head -1 $${PAGE}qt`; \
	    if [ $$# -eq 3 ] && [ "$$2" = .so ]; then \
		${LN} -sf `basename $$3 | ${SED} s/qt$$//` \
		${PREFIX}/man/man3/$${PAGE}; \
	    else \
		${INSTALL_MAN} $${PAGE}qt \
		${PREFIX}/man/man3/$${PAGE}; \
	    fi; \
	 done)
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/qt
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.QT ${PREFIX}/share/doc/qt/

.include "../../mk/bsd.pkg.mk"
