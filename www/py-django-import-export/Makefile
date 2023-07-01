# $NetBSD: Makefile,v 1.16 2023/07/01 08:37:46 wiz Exp $

DISTNAME=	django-import-export-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-import-export/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/django-import-export/django-import-export
COMMENT=	Django application and library for importing and exporting data
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-diff-match-patch-[0-9]*:../../textproc/py-diff-match-patch
DEPENDS+=	${PYPKGPREFIX}-django>=2.0:../../www/py-django2
DEPENDS+=	${PYPKGPREFIX}-tablib>=0.14.0:../../textproc/py-tablib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
