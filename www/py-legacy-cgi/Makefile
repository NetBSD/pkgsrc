# $NetBSD: Makefile,v 1.4 2025/04/23 15:18:14 adam Exp $

DISTNAME=	legacy_cgi-2.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/legacy_cgi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jackrosenthal/legacy-cgi
COMMENT=	Fork of the standard cgi and cgitb modules, deprecated in PEP-594
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>0:../../devel/py-hatchling

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	cgi.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
