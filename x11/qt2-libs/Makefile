# $NetBSD: Makefile,v 1.6 2000/12/11 23:03:31 skrll Exp $
#
USE_MESA=	yes

.include "../qt2-libs/Makefile.common"

PKGNAME=	qt2-libs-${QTVERSION}

DEPENDS+=	png-*:../../graphics/png
DEPENDS+=	jpeg-*:../../graphics/jpeg

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
