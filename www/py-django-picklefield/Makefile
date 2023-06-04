# $NetBSD: Makefile,v 1.1 2023/06/04 02:53:08 markd Exp $

DISTNAME=	django-picklefield-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-picklefield/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gintas/django-picklefield
COMMENT=	Pickled object field for Django
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
