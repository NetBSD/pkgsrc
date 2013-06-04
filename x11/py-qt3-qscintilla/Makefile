# $NetBSD: Makefile,v 1.37 2013/06/04 22:17:29 tron Exp $
#

.include "../../x11/py-qt3-base/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-qt3-qscintilla-${PYQT_VERSION}
PKGREVISION=		12

COMMENT=		Python binding for QScintilla

CONFIGURE_ARGS+=	-n ${QTDIR}/include
CONFIGURE_ARGS+=	-o ${QTDIR}/lib

INSTALL_DIRS=	qtext

.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../x11/qt3-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
