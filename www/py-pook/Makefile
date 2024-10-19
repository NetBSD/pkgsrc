# $NetBSD: Makefile,v 1.7 2024/10/19 05:56:24 adam Exp $

DISTNAME=	pook-2.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/h2non/pook
COMMENT=	HTTP traffic mocking and expectations made easy
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-furl>=0.5.6:../../www/py-furl
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=2.5.1:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0.11.0:../../textproc/py-xmltodict
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.20.3:../../devel/py-test-asyncio
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-pook>=0.1.0b0:../../devel/py-test-pook

USE_LANGUAGES=	# none

post-extract:
	${MKDIR} ${WRKSRC}/src
	${MV} ${WRKSRC}/pook ${WRKSRC}/src/pook

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
