# $NetBSD: Makefile,v 1.24 2004/04/11 22:45:44 snj Exp $

PKGNAME=	qt2-libs-${QTVERSION}
PKGREVISION=	5
COMMENT=	C++ X GUI toolkit

USE_BUILDLINK3=	yes

.include "../qt2-libs/Makefile.common"

CONFIGURE_ENV+=		QTDIR="${WRKSRC}"
MAKE_ENV+=		QTDIR="${WRKSRC}"
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

ALL_TARGET=		sub-src

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqt.la ${QTPREFIX}/lib
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/* ${QTPREFIX}/include

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
