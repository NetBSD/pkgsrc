# $NetBSD: Makefile,v 1.1 2022/05/25 15:28:50 kleink Exp $

DISTNAME=	WTForms-Appengine-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-Appengine/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/wtforms/wtforms-appengine
COMMENT=	Appengine tools for WTForms
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.5:../../www/py-wtforms

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
