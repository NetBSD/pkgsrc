# $NetBSD: Makefile,v 1.10 2002/03/14 13:57:53 tron Exp $
#

.include "../qt2-libs/Makefile.common"

PKGNAME=		qt2-designer-kde-${QTVERSION}
PKGREVISION=		2
COMMENT=		Visual (WYSIWYG) QT GUI builder with KDE widget support

CONFLICTS+=		qt2-designer-[0-9]*

USE_BUILDLINK_ONLY=		yes
BUILDLINK_DEPENDS.qt2-libs=	qt2-libs>=${QTVERSION}nb2

CONFIGURE_ARGS+=	-kde
CONFIGURE_ENV+=		QTDIR="${QTPREFIX}" \
			KDEDIR="${BUILDLINK_DIR}"
MAKE_ENV+=		QTDIR=${QTPREFIX} \
			KDEDIR="${BUILDLINK_DIR}"

ALL_TARGET=		sub-tools
UNLIMIT_RESOURCES=	datasize

do-install:
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/tools/designer/util/libqutil.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/uic/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin

.include "../../x11/kdelibs2/buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
