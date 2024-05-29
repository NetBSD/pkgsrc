# $NetBSD: Makefile,v 1.30 2024/05/29 16:35:09 adam Exp $

PKGREVISION= 2
.include "../../x11/qt5-qscintilla/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-qt5-${DISTNAME:S/_src//:tl}
COMMENT=	QScintilla -- Python bindings

TOOL_DEPENDS+=	${PYPKGPREFIX}-sip6>=6.0.2:../../x11/py-sip6
TOOL_DEPENDS+=	${PYPKGPREFIX}-qt-builder>=1.6:../../x11/py-qt-builder
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5

WRKSRC=		${WRKDIR}/${DISTNAME}/Python

PYTHON_VERSIONS_INCOMPATIBLE=	27

WHEEL_NAME=	${DISTNAME:S/_src//}

post-extract:
	cd ${WRKSRC} && ${CP} pyproject-qt5.toml pyproject.toml

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/PyQt5/Qsci.abi3.so \
	${DESTDIR}${PREFIX}/${PYSITELIB}/PyQt5/Qsci.abi3.so
.endif

.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.qt5-qscintilla+=	qt5-qscintilla>=${PKGVERSION_NOREV}
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
