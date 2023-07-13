# $NetBSD: Makefile,v 1.3 2023/07/13 10:03:27 wiz Exp $

DISTNAME=	django-haystack-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-haystack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://haystacksearch.org/
COMMENT=	Modular search for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
