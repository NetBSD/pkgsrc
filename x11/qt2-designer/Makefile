# $NetBSD: Makefile,v 1.24 2005/04/16 00:54:33 kristerw Exp $

PKGNAME=		qt2-designer-${QTVERSION}
PKGREVISION=		3
COMMENT=		Visual (WYSIWYG) QT GUI builder

CONFLICTS+=		qt2-designer-kde-[0-9]*


.include "../qt2-libs/Makefile.common"

BUILD_TARGET=		sub-tools

do-install:
	${LIBTOOL} ${INSTALL_DATA} \
		${WRKSRC}/tools/designer/util/libqutil.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} \
		${WRKSRC}/tools/designer/uic/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} \
		${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/qt2-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
