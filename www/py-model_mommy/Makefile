# $NetBSD: Makefile,v 1.10 2023/07/13 10:03:30 wiz Exp $

DISTNAME=	model_mommy-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/model_mommy/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/vandersonmota/model_mommy
COMMENT=	Smart object creation facility for Django
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
