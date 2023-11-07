# $NetBSD: Makefile,v 1.5 2023/11/07 22:38:10 wiz Exp $

DISTNAME=	wstools-0.4.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wstools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pycontribs/wstools
COMMENT=	WSDL parsing services package for Web Services
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TOOL_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
