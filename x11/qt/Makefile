# $NetBSD: Makefile,v 1.27 1999/07/08 08:06:59 agc Exp $
#

DISTNAME=	qt-1.44
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.troll.no/qt/source/ \
		ftp://ftp.fu-berlin.de/unix/X11/gui/Qt/source/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.troll.no/products/qt.html

CONFLICTS=	qt-1.*

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

MAKE_ENV=	QTDIR=${WRKSRC}
ALL_TARGET=	src

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	egcs-1.1.2:../../lang/egcs
CXX=		${LOCALBASE}/egcs/bin/g++
.endif

do-configure:
	@cd ${WRKSRC} && ${MAKE} QTDIR=${WRKSRC} ${LOWER_OPSYS}-g++-static

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
		${RM} -f ${PREFIX}/man/man3/$${PAGE}; \
		${LN} -s `basename $$3 | ${SED} s/qt$$//` \
		${PREFIX}/man/man3/$${PAGE}; \
	    else \
		${INSTALL_MAN} $${PAGE}qt \
		${PREFIX}/man/man3/$${PAGE}; \
	    fi; \
	 done)
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/qt
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.QT ${PREFIX}/share/doc/qt/

.include "../../mk/bsd.pkg.mk"
