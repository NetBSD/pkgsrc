# $NetBSD: Makefile,v 1.16 2001/11/29 01:12:52 hubertf Exp $
#
#USE_MESA=		yes

.include "../qt2-libs/Makefile.common"

PKGNAME=		qt2-libs-${QTVERSION}
PKGREVISION=	1
COMMENT=		C++ X GUI toolkit

USE_BUILDLINK_ONLY=	yes
CONFIGURE_ARGS+=	-I${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	-L${BUILDLINK_DIR}/lib

CONFIGURE_ENV+=		QTDIR="${WRKSRC}"
MAKE_ENV+=		QTDIR="${WRKSRC}"

ALL_TARGET=		sub-src

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/src/libqt.la ${QTPREFIX}/lib
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/* ${QTPREFIX}/include

.include "../../devel/zlib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../graphics/mng/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
