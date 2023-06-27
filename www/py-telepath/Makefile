# $NetBSD: Makefile,v 1.2 2023/06/27 13:05:00 adam Exp $

DISTNAME=	telepath-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/telepath/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/telepath
COMMENT=	Data exchange library between Django and browser
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m django test --settings=telepath.test_settings

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
