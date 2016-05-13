# $NetBSD: Makefile,v 1.1 2016/05/13 20:02:26 adam Exp $

DISTNAME=	django-formtools-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-formtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://django-formtools.readthedocs.io/
COMMENT=	Collection of assorted utilities for specific form use cases
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
