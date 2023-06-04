# $NetBSD: Makefile,v 1.1 2023/06/04 01:45:35 markd Exp $

DISTNAME=	django-gravatar2-1.4.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-gravatar2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twaddington/django-gravatar
COMMENT=	Essential Gravatar support for Django
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-django>=2.2:../../www/py-django2

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
