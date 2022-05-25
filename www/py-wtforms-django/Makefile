# $NetBSD: Makefile,v 1.1 2022/05/25 15:36:09 kleink Exp $

DISTNAME=	WTForms-Django-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-Django/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/wtforms/wtforms-django
COMMENT=	Django tools for WTForms
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-wtforms>=2.1:../../www/py-wtforms

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
