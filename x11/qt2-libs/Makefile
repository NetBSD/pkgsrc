# $NetBSD: Makefile,v 1.22 2003/11/30 22:58:40 jschauma Exp $

PKGNAME=	qt2-libs-${QTVERSION}
PKGREVISION=	5
COMMENT=	C++ X GUI toolkit

USE_BUILDLINK2=	yes

.include "../qt2-libs/Makefile.common"

CONFIGURE_ARGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
CONFIGURE_ARGS+=	-I${LOCALBASE}/include/freetype2
CONFIGURE_ARGS+=	-I${X11BASE}/include/freetype2
CONFIGURE_ARGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib

CONFIGURE_ENV+=		QTDIR="${WRKSRC}"
MAKE_ENV+=		QTDIR="${WRKSRC}"
MAKE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

ALL_TARGET=		sub-src

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/lib
	${PKGLIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqt.la ${QTPREFIX}/lib
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/* ${QTPREFIX}/include

.include "../../devel/zlib/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
