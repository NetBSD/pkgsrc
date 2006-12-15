# $NetBSD: Makefile,v 1.32 2006/12/15 20:33:04 joerg Exp $

PKGNAME=	qt2-libs-${QTVERSION}
PKGREVISION=	9
COMMENT=	C++ X GUI toolkit


.include "../../x11/qt2-libs/Makefile.common"

CONFIGURE_ENV+=		QTDIR=${WRKSRC:Q}
MAKE_ENV+=		QTDIR=${WRKSRC:Q}
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH:Q}

BUILD_TARGET=		sub-src

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqt.la ${QTPREFIX}/lib
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/* ${QTPREFIX}/include

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
