# $NetBSD: Makefile,v 1.1 2023/06/04 02:47:57 markd Exp $

DISTNAME=	django-haystack-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-haystack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://haystacksearch.org/
COMMENT=	Modular search for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
