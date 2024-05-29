# $NetBSD: Makefile,v 1.3 2024/05/29 16:35:09 adam Exp $

PKGREVISION= 2
.include "../../x11/qt6-qscintilla/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-qt6-${DISTNAME:S/_src//:tl}
COMMENT=	QScintilla -- Python bindings

TOOL_DEPENDS+=	${PYPKGPREFIX}-sip6>=6.0.2:../../x11/py-sip6
TOOL_DEPENDS+=	${PYPKGPREFIX}-qt-builder>=1.6:../../x11/py-qt-builder
DEPENDS+=	${PYPKGPREFIX}-qt6-[0-9]*:../../x11/py-qt6

WRKSRC=		${WRKDIR}/${DISTNAME}/Python

PYTHON_VERSIONS_INCOMPATIBLE=	27

WHEEL_NAME=	PyQt6_${DISTNAME:S/_src//}

post-extract:
	cd ${WRKSRC} && ${CP} pyproject-qt6.toml pyproject.toml

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${PREFIX}/${PYSITELIB}/PyQt6/Qsci.abi3.so \
	${DESTDIR}${PREFIX}/${PYSITELIB}/PyQt6/Qsci.abi3.so
.endif

.include "../../lang/python/wheel.mk"
BUILDLINK_API_DEPENDS.qt6-qscintilla+=	qt6-qscintilla>=${PKGVERSION_NOREV}
.include "../../x11/qt6-qscintilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
