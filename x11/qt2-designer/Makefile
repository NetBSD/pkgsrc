# $NetBSD: Makefile,v 1.18 2003/05/02 12:34:24 wiz Exp $

PKGNAME=		qt2-designer-${QTVERSION}
PKGREVISION=		2
COMMENT=		Visual (WYSIWYG) QT GUI builder

CONFLICTS+=		qt2-designer-kde-[0-9]*

USE_BUILDLINK2=		yes

.include "../qt2-libs/Makefile.common"

ALL_TARGET=		sub-tools

do-install:
	${PKGLIBTOOL} ${INSTALL_DATA} \
		${WRKSRC}/tools/designer/util/libqutil.la ${QTPREFIX}/lib
	${PKGLIBTOOL} ${INSTALL_PROGRAM} \
		${WRKSRC}/tools/designer/uic/uic ${QTPREFIX}/bin
	${PKGLIBTOOL} ${INSTALL_PROGRAM} \
		${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin

.include "../../x11/qt2-libs/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
