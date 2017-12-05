# $NetBSD: Makefile,v 1.3 2017/12/05 09:29:32 adam Exp $

DISTNAME=	django-import-export-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-import-export/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bmihelac/django-import-export
COMMENT=	Django application and library for importing and exporting data
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-diff-match-patch-[0-9]*:../../textproc/py-diff-match-patch
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-tablib>=0.9:../../textproc/py-tablib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
