# $NetBSD: Makefile,v 1.12 2023/07/13 10:03:27 wiz Exp $

DISTNAME=	django-formtools-2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-formtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-formtools.readthedocs.io/
COMMENT=	Collection of assorted utilities for specific form use cases
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
