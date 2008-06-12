# $NetBSD: Makefile,v 1.23 2008/06/12 02:14:57 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/py-qt3-base/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-qt3-qscintilla-${PYQT_VERSION}
PKGREVISION=		3

COMMENT=		Python binding for QScintilla

CONFIGURE_ARGS+=	-n ${QTDIR}/include
CONFIGURE_ARGS+=	-o ${QTDIR}/lib

INSTALL_DIRS=	${WRKSRC}/qtext

.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../x11/qt3-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
