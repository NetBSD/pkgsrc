# $NetBSD: Makefile,v 1.2 2023/04/30 18:58:53 wiz Exp $

DISTNAME=	django-localflavor-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-localflavor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-localflavor.readthedocs.io/en/latest/
COMMENT=	L18N support for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-stdnum-[0-9]*:../../misc/py-stdnum

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
