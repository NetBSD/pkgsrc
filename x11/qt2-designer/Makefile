# $NetBSD: Makefile,v 1.16 2002/03/13 17:38:01 fredb Exp $
#

.include "../qt2-libs/Makefile.common"

PKGNAME=		qt2-designer-${QTVERSION}
PKGREVISION=		2
COMMENT=		Visual (WYSIWYG) QT GUI builder

CONFLICTS+=		qt2-designer-kde-[0-9]*

USE_BUILDLINK_ONLY=		yes
BUILDLINK_DEPENDS.qt2-libs=	qt2-libs>=${QTVERSION}nb2

ALL_TARGET=		sub-tools

do-install:
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/tools/designer/util/libqutil.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/uic/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin

.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
