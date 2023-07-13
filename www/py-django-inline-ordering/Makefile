# $NetBSD: Makefile,v 1.5 2023/07/13 10:03:28 wiz Exp $

DISTNAME=	django-inline-ordering-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-inline-ordering/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/centralniak/django-inline-ordering
COMMENT=	Django app to ease ordering of related data
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=		# empty

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
