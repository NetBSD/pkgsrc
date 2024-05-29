# $NetBSD: Makefile,v 1.11 2024/05/29 16:35:09 adam Exp $

DISTNAME=	pyotherside-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	8
CATEGORIES=	x11 lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=thp/}
GITHUB_PROJECT=	pyotherside
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thp/pyotherside/
COMMENT=	Python Bindings for Qt
LICENSE=	isc

USE_LANGUAGES=	c++

MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake PYTHON_CONFIG=python${PYVERSSUFFIX}-config

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${QTDIR}/qml/io/thp/pyotherside/libpyothersideplugin.dylib \
	${DESTDIR}${QTDIR}/qml/io/thp/pyotherside/libpyothersideplugin.dylib
.endif

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
