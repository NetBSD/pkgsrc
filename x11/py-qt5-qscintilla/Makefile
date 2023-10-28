# $NetBSD: Makefile,v 1.25 2023/10/28 19:57:26 wiz Exp $

PKGREVISION= 2
.include "../../x11/qt5-qscintilla/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-qt5-${DISTNAME:S/_src//:tl}
COMMENT=	QScintilla -- Python bindings

TOOL_DEPENDS+=	${PYPKGPREFIX}-sip6-[0-9]*:../../x11/py-sip6
TOOL_DEPENDS+=	${PYPKGPREFIX}-qt-builder-[0-9]*:../../x11/py-qt-builder
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5

WRKSRC=		${WRKDIR}/${DISTNAME}/Python

PYTHON_VERSIONS_INCOMPATIBLE=	27

WHEEL_NAME=	${DISTNAME:S/_src//}

post-extract:
	cd ${WRKSRC} && ${CP} pyproject-qt5.toml pyproject.toml

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.qt5-qscintilla+=	qt5-qscintilla>=${PKGVERSION_NOREV}
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
