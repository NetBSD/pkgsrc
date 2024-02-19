# $NetBSD: Makefile,v 1.22 2024/02/19 18:19:27 adam Exp $

DISTNAME=	jsbeautifier-1.15.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsbeautifier/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://beautifier.io/
COMMENT=	JavaScript unobfuscator and beautifier
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-editorconfig-core>=0.12.2:../../devel/py-editorconfig-core
DEPENDS+=	${PYPKGPREFIX}-six>=1.13.0:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} js-beautify js-beautify-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
