# $NetBSD: Makefile,v 1.3.2.1 2002/05/11 02:09:33 jlam Exp $

PKGNAME=		qt3-libs-${QTVERSION}
COMMENT=		C++ X GUI toolkit

USE_BUILDLINK2_ONLY=	yes

.include "../qt3-libs/Makefile.common"

ALL_TARGET=		sub-src

post-extract:
	${RM} -f ${WRKSRC}/include/qt_windows.h

do-install:
	${INSTALL_DATA_DIR} ${QTPREFIX}
	${INSTALL_PROGRAM_DIR} ${QTPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/moc ${QTPREFIX}/bin
	${INSTALL_DATA_DIR} ${QTPREFIX}/lib
	${PKGLIBTOOL} ${INSTALL_DATA} ${WRKSRC}/lib/libqt.la ${QTPREFIX}/lib
	${INSTALL_DATA_DIR} ${QTPREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${QTPREFIX}/include
	${INSTALL_DATA_DIR} ${QTPREFIX}/include/private
	${INSTALL_DATA} ${WRKSRC}/include/private/*.h ${QTPREFIX}/include/private

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/mng/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
