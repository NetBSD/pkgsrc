# $NetBSD: Makefile,v 1.10.2.2 2002/06/21 23:05:55 jlam Exp $
#

PKGNAME=		qt2-designer-kde-${QTVERSION}
PKGREVISION=		2
COMMENT=		Visual (WYSIWYG) QT GUI builder with KDE widget support

CONFLICTS+=		qt2-designer-[0-9]*

USE_BUILDLINK2=		yes
BUILDLINK_DEPENDS.qt2-libs=	qt2-libs>=${QTVERSION}nb2

.include "../qt2-libs/Makefile.common"

CONFIGURE_ARGS+=	-kde
CONFIGURE_ENV+=		KDEDIR="${KDEDIR}"
MAKE_ENV+=		KDEDIR="${KDEDIR}"

ALL_TARGET=		sub-tools
UNLIMIT_RESOURCES=	datasize

do-install:
	${PKGLIBTOOL} ${INSTALL_DATA} \
		${WRKSRC}/tools/designer/util/libqutil.la ${QTPREFIX}/lib
	${PKGLIBTOOL} ${INSTALL_PROGRAM} \
		${WRKSRC}/tools/designer/uic/uic ${QTPREFIX}/bin
	${PKGLIBTOOL} ${INSTALL_PROGRAM} \
		${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin

.include "../../x11/kdelibs2/buildlink.mk"

.include "../../mk/bsd.pkg.mk"
