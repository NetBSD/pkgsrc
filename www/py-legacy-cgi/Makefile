# $NetBSD: Makefile,v 1.2 2025/01/15 07:59:03 adam Exp $

DISTNAME=	legacy_cgi-2.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/legacy_cgi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jackrosenthal/legacy-cgi
COMMENT=	Fork of the standard cgi and cgitb modules, deprecated in PEP-594
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.0.0:../../devel/py-poetry-core

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	cgi.py

# substitute for 'cgi' in < 3.13
PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
