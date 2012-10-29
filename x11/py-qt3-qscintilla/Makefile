# $NetBSD: Makefile,v 1.33 2012/10/29 05:06:45 asau Exp $
#

.include "../../x11/py-qt3-base/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-qt3-qscintilla-${PYQT_VERSION}
PKGREVISION=		8

COMMENT=		Python binding for QScintilla

CONFIGURE_ARGS+=	-n ${QTDIR}/include
CONFIGURE_ARGS+=	-o ${QTDIR}/lib

INSTALL_DIRS=	qtext

.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../x11/qt3-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
