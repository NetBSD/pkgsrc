# $NetBSD: Makefile,v 1.1.1.1 2000/03/23 21:27:40 dmcmahill Exp $
#

DISTNAME=	qt-1.44
PKGNAME=	qt1-1.44
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.troll.no/qt/source/ \
		ftp://ftp.fu-berlin.de/unix/X11/gui/Qt/source/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.troll.no/products/qt.html

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

.if defined(USE_GIF)
pre-build:
	cd ${WRKSRC} && ${PATCH} <${FILESDIR}/enablegif.patch
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc1 ${PREFIX}/bin/moc1
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqt1.la ${PREFIX}/lib/
	${INSTALL_DATA_DIR} ${PREFIX}/include/qt1
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/qt1/
	${INSTALL_MAN} ${WRKSRC}/man/man1/moc.1 ${PREFIX}/man/man1/moc1.1
	@cd ${WRKSRC}/man/man3; PAGES="`ls -1 | ${SED} -e 's,\.3qt$$,,'`"; \
	(for PAGE in $$PAGES; do \
	    ${ECHO} installing ${PREFIX}/man/man3/$${PAGE}_1.3; \
	    set - X `head -1 $${PAGE}.3qt`; \
	    if [ $$# -eq 3 ] && [ "$$2" = .so ]; then \
		${RM} -f ${PREFIX}/man/man3/$${PAGE}_1.3 ;\
		${LN} -s `basename $$3 | ${SED} s/\.3qt$$/_1\.3/` \
		${PREFIX}/man/man3/$${PAGE}_1.3; \
	    else \
		${INSTALL_MAN} $${PAGE}.3qt \
		${PREFIX}/man/man3/$${PAGE}_1.3; \
	    fi; \
	 done)
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/qt1
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.QT ${PREFIX}/share/doc/qt1/

.include "../../mk/bsd.pkg.mk"
