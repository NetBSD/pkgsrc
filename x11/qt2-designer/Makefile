# $NetBSD: Makefile,v 1.3 2000/11/03 08:37:05 skrll Exp $
#

PKGNAME=	qt2-designer-2.2.1

.include "../qt2-libs/Makefile.common"

DEPENDS+=	qt2-libs-*:../../x11/qt2-libs

ALL_TARGET=	sub-tools

PATCHFILES+=	${PKGSRCDIR}/x11/qt2-libs/patches/patch-??
ALLFILES=	${DISTFILES} # don't checksum shared patches

CONFIGURE_ENV+=	QTDIR=${QTPREFIX}
MAKE_ENV=	QTDIR=${QTPREFIX}

do-install:
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/tools/designer/util/libqutil.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/uic/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin

.include "../../mk/bsd.pkg.mk"
