# $NetBSD: Makefile,v 1.1 2019/01/07 12:56:22 adam Exp $

DISTNAME=	django-timezone-field-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-timezone-field/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mfogel/django-timezone-field
COMMENT=	Database and form fields for pytz timezone objects
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
