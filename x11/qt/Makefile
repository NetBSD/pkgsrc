# $NetBSD: Makefile,v 1.32 2000/04/14 21:11:59 dmcmahill Exp $
#

DISTNAME=	qt-2.0.2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.troll.no/qt/source/ \
		ftp://ftp.fu-berlin.de/unix/X11/gui/Qt/source/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.troll.no/products/qt.html

DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	png-*:../../graphics/png

NOT_FOR_PLATFORM=    *-*-alpha	# builds, but programs linked to qt crash

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

do-install:
	${INSTALL_PROGRAM_DIR} ${X11BASE}/bin/qt2
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${X11BASE}/bin/qt2
	${INSTALL_DATA_DIR} ${X11BASE}/lib/qt2
	@${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqt.la ${X11BASE}/lib/qt2
	${INSTALL_DATA_DIR} ${X11BASE}/include/qt2
	${INSTALL_DATA} ${WRKSRC}/include/* ${X11BASE}/include/qt2
	${INSTALL_MAN_DIR}  ${X11BASE}/man/qt2/man1
	${INSTALL_MAN_DIR}  ${X11BASE}/man/qt2/man3
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${X11BASE}/man/qt2/man1
	@cd ${WRKSRC}/man/man3; PAGES="`ls -1 | ${SED} -e 's,3qt$$,3,'`"; \
	(for PAGE in $$PAGES; do \
	    ${ECHO} installing ${X11BASE}/man/qt2/man3/$${PAGE}; \
	    set - X `head -1 $${PAGE}qt`; \
	    if [ $$# -eq 3 ] && [ "$$2" = .so ]; then \
		${LN} -fs `basename $$3 | ${SED} s/qt$$//` \
		  ${X11BASE}/man/qt2/man3/$${PAGE}; \
	    else \
		${INSTALL_MAN} $${PAGE}qt ${X11BASE}/man/qt2/man3/$${PAGE}; \
	    fi; \
	 done)
	${INSTALL_DATA_DIR} ${X11BASE}/share/doc/qt2
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.QT \
	  ${WRKSRC}/doc/* ${X11BASE}/share/doc/qt2

.include "../../mk/bsd.pkg.mk"
