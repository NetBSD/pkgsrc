# $NetBSD: Makefile,v 1.20 2004/10/03 00:18:37 tv Exp $
#

PKGNAME=		qt2-designer-kde-${QTVERSION}
PKGREVISION=		8
COMMENT=		Visual (WYSIWYG) QT GUI builder with KDE widget support

CONFLICTS+=		qt2-designer-[0-9]*

USE_BUILDLINK3=		yes
BUILDLINK_DEPENDS.qt2-libs=	qt2-libs>=${QTVERSION}nb2

.include "../qt2-libs/Makefile.common"

CONFIGURE_ARGS+=	-kde
CONFIGURE_ENV+=		KDEDIR="${KDEDIR}"
MAKE_ENV+=		KDEDIR="${KDEDIR}"

ALL_TARGET=		sub-tools
UNLIMIT_RESOURCES=	datasize

do-install:
	${LIBTOOL} ${INSTALL_DATA} \
		${WRKSRC}/tools/designer/util/libqutil.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} \
		${WRKSRC}/tools/designer/uic/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} \
		${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin

.include "../../x11/kdelibs2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
