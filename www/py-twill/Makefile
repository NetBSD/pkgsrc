# $NetBSD: Makefile,v 1.23 2024/05/07 19:15:09 adam Exp $

DISTNAME=	twill-3.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twill/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twill-tools/twill
COMMENT=	Simple scripting language for web browsing
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=69:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-lxml>=4.9:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=3.1:../../devel/py-pyparsing
#TEST_DEPENDS+=	${PYPKGPREFIX}-pytidylib>=0.3
#TEST_DEPENDS+=	${PYPKGPREFIX}-quixote>=3.6:../../devel/py-quixote
#TEST_DEPENDS+=	${PYPKGPREFIX}-tox>=4:../../devel/py-tox

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in twill twill-fork
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
