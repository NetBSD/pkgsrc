# $NetBSD: Makefile,v 1.1 2001/05/14 17:09:26 drochner Exp $
#

.include "../qt2-libs/Makefile.common"

PKGNAME=		qt2-designer-kde-${QTVERSION}

COMMENT=		Visual (WYSIWYG) QT GUI builder

DEPENDS+=		qt2-libs-${QTVERSION}:../../x11/qt2-libs
DEPENDS+=		kdelibs-2.1nb1:../../x11/kdelibs2
DEPENDS+=		qt2-designer-${QTVERSION}:../qt2-designer

ALL_TARGET=		sub-tools

EVAL_PREFIX+=           KDEBASEDIR=kdelibs

CONFIGURE_ARGS+=	-kde
CONFIGURE_ENV+=		QTDIR="${QTPREFIX}" \
			KDEDIR="${KDEBASEDIR}"
MAKE_ENV+=		QTDIR=${QTPREFIX} \
			KDEDIR="${KDEBASEDIR}"

do-install:
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin/designer-kde

.include "../../mk/bsd.pkg.mk"
