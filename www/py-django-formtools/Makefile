# $NetBSD: Makefile,v 1.3 2017/10/05 12:20:55 adam Exp $

DISTNAME=	django-formtools-2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-formtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://django-formtools.readthedocs.io/
COMMENT=	Collection of assorted utilities for specific form use cases
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
