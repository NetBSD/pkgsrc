# $NetBSD: Makefile,v 1.9 2022/01/04 20:55:39 wiz Exp $

DISTNAME=	WTForms-Components-0.10.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/WTForms-Components/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/wtforms-components
COMMENT=	Additional fields, validators and widgets for WTForms
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-intervals>=0.6.0:../../math/py-intervals
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-validators>=0.5.0:../../textproc/py-validators
DEPENDS+=	${PYPKGPREFIX}-wtforms>=1.0.4:../../www/py-wtforms

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-validators

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
