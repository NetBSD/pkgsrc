# $NetBSD: Makefile,v 1.1 2022/05/25 15:33:21 kleink Exp $

DISTNAME=	WTForms-dateutil-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-dateutil/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/wtforms/wtforms-dateutil
COMMENT=	WTForms fields using dateutil
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.5:../../www/py-wtforms

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
