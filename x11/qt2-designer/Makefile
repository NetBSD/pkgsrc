# $NetBSD: Makefile,v 1.9 2001/05/01 09:46:38 skrll Exp $
#

.include "../qt2-libs/Makefile.common"

PKGNAME=		qt2-designer-${QTVERSION}

COMMENT=		Visual (WYSIWYG) QT GUI builder

DEPENDS+=		qt2-libs-${QTVERSION}:../../x11/qt2-libs
DEPENDS+=		kdelibs-2.1nb1:../../x11/kdelibs2

ALL_TARGET=		sub-tools

EVAL_PREFIX+=           KDEBASEDIR=kdelibs

CONFIGURE_ARGS+=	-kde
CONFIGURE_ENV+=		QTDIR="${QTPREFIX}" \
			KDEDIR="${KDEBASEDIR}"
MAKE_ENV+=		QTDIR=${QTPREFIX} \
			KDEDIR="${KDEBASEDIR}"

do-install:
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/tools/designer/util/libqutil.la ${QTPREFIX}/lib
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/uic/uic ${QTPREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/tools/designer/designer/designer ${QTPREFIX}/bin

.include "../../mk/bsd.pkg.mk"
