# $NetBSD: Makefile,v 1.6 2001/02/06 09:26:11 skrll Exp $
#

.include "../qt2-libs/Makefile.common"

PKGNAME=	qt2-designer-${QTVERSION}

DEPENDS+=	qt2-libs-${QTVERSION}:../../x11/qt2-libs

ALL_TARGET=	sub-tools

CONFIGURE_ENV+=	QTDIR=${QTPREFIX}
MAKE_ENV+=	QTDIR=${QTPREFIX}

do-install:
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/tools/designer/util/libqutil.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/uic/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin

.include "../../mk/bsd.pkg.mk"
