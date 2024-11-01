# $NetBSD: Makefile,v 1.1 2024/11/01 00:07:59 wiz Exp $

DISTNAME=	legacy_cgi-2.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=l/legacy_cgi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/legacy_cgi/
COMMENT=	Fork of the standard library cgi and cgitb modules, being deprecated in PEP-594
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	cgi.py

# substitute for 'cgi' in < 3.13
PYTHON_VERSIONS_INCOMPATIBLE=	39 310 311 312

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
