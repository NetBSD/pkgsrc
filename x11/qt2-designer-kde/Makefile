# $NetBSD: Makefile,v 1.2 2001/07/15 10:53:45 jlam Exp $
#

.include "../qt2-libs/Makefile.common"

PKGNAME=		qt2-designer-kde-${QTVERSION}

COMMENT=		Visual (WYSIWYG) QT GUI builder

USE_BUILDLINK_ONLY=		yes
BUILDLINK_DEPENDS.qt2-designer=	qt2-designer-${QTVERSION}
BUILDLINK_DEPENDS.qt2-libs=	qt2-libs-${QTVERSION}

ALL_TARGET=		sub-tools

CONFIGURE_ARGS+=	-kde
CONFIGURE_ENV+=		QTDIR="${QTPREFIX}" \
			KDEDIR="${BUILDLINK_DIR}"
MAKE_ENV+=		QTDIR=${QTPREFIX} \
			KDEDIR="${BUILDLINK_DIR}"

do-install:
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin/designer-kde

.include "../../x11/kdelibs2/buildlink.mk"
.include "../../x11/qt2-designer/buildlink.mk"
.include "../../x11/qt2-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
