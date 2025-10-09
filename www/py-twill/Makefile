# $NetBSD: Makefile,v 1.30 2025/10/09 07:58:12 wiz Exp $

DISTNAME=	twill-3.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twill/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twill-tools/twill
COMMENT=	Simple scripting language for web browsing
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-httpx>=0.27.0:../../www/py-httpx
DEPENDS+=	${PYPKGPREFIX}-lxml>=5.2:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=3.1:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-flask>=3.0:../../www/py-flask
#TEST_DEPENDS+=	${PYPKGPREFIX}-pytidylib>=0.3
TEST_DEPENDS+=	${PYPKGPREFIX}-tox>=4:../../devel/py-tox

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
.for bin in twill twill-fork
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
