# $NetBSD: Makefile,v 1.20 2004/04/11 22:47:15 snj Exp $

PKGNAME=		qt2-designer-${QTVERSION}
PKGREVISION=		2
COMMENT=		Visual (WYSIWYG) QT GUI builder

CONFLICTS+=		qt2-designer-kde-[0-9]*

USE_BUILDLINK3=		yes

.include "../qt2-libs/Makefile.common"

ALL_TARGET=		sub-tools

do-install:
	${LIBTOOL} ${INSTALL_DATA} \
		${WRKSRC}/tools/designer/util/libqutil.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} \
		${WRKSRC}/tools/designer/uic/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} \
		${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin

.include "../../x11/qt2-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
