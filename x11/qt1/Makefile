# $NetBSD: Makefile,v 1.15 2004/04/24 22:38:22 snj Exp $
#

DISTNAME=	qt-1.44
PKGNAME=	qt1-1.44
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.troll.no/qt/source/ \
		ftp://ftp.fu-berlin.de/unix/X11/gui/Qt/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.troll.no/products/qt.html
COMMENT=	C++ X GUI toolkit

USE_BUILDLINK3=	yes
USE_X11BASE=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

QTPREFIX=${PREFIX}/qt1

MAKE_ENV=	QTDIR=${WRKSRC} QTPREFIX=${QTPREFIX}
MAKE_ENV+=	CXXOPTS="${CFLAGS}"
ALL_TARGET=	src

.include "../../mk/bsd.prefs.mk"

do-configure:
	@cd ${WRKSRC} && ${MAKE} QTDIR=${WRKSRC} ${LOWER_OPSYS}-g++-static

.if defined(USE_GIF)
post-patch:
	cd ${WRKSRC} && ${PATCH} <${FILESDIR}/enablegif.patch
.endif

do-install:
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/lib
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqt.la ${QTPREFIX}/lib/
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/* ${QTPREFIX}/include/
	${INSTALL_MAN_DIR} ${QTPREFIX}/man/man1
	${INSTALL_MAN_DIR} ${QTPREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/man/man1/moc.1 ${QTPREFIX}/man/man1/moc.1
	@cd ${WRKSRC}/man/man3; PAGES="`ls -1 | ${SED} -e 's,\.3qt$$,,'`"; \
	(for PAGE in $$PAGES; do \
	    ${ECHO} installing ${QTPREFIX}/man/man3/$${PAGE}.3; \
	    set - X `head -1 $${PAGE}.3qt`; \
	    if [ $$# -eq 3 ] && [ "$$2" = .so ]; then \
		${RM} -f ${QTPREFIX}/man/man3/$${PAGE}.3 ;\
		${LN} -s `basename $$3 | ${SED} s/\.3qt$$/\.3/` \
		${QTPREFIX}/man/man3/$${PAGE}.3; \
	    else \
		${INSTALL_MAN} $${PAGE}.3qt \
		${QTPREFIX}/man/man3/$${PAGE}.3; \
	    fi; \
	 done)
	${INSTALL_DATA_DIR} ${QTPREFIX}/share/doc/qt
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.QT ${QTPREFIX}/share/doc/qt/
	${INSTALL_DATA_DIR} ${QTPREFIX}/share/doc/qt/html
	${INSTALL_DATA} ${WRKSRC}/html/* ${QTPREFIX}/share/doc/qt/html

.include "../../mk/bsd.pkg.mk"
