# $NetBSD: Makefile,v 1.9 2023/10/28 19:57:25 wiz Exp $

DISTNAME=	terminado-0.17.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/terminado/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/takluyver/terminado
COMMENT=	Terminals served to term.js using Tornado websockets
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-ptyprocess-[0-9]*:../../sysutils/py-ptyprocess
DEPENDS+=	${PYPKGPREFIX}-tornado>=6.1.0:../../www/py-tornado
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
