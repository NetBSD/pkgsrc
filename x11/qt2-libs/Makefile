# $NetBSD: Makefile,v 1.1.1.1 2000/10/19 07:41:12 skrll Exp $
#

.include "../qt2-libs/Makefile.common"

PKGNAME=	qt2-libs-2.2.1

DEPENDS+=	png-*:../../graphics/png
DEPENDS+=	jpeg-*:../../graphics/jpeg

USE_MESA=	yes

CONFIGURE_ENV+=	QTDIR=${WRKSRC}
MAKE_ENV+=	QTDIR=${WRKSRC}

ALL_TARGET=		sub-src

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqt.la ${QTPREFIX}/lib
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/* ${QTPREFIX}/include

.include "../../mk/bsd.pkg.mk"
