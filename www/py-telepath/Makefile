# $NetBSD: Makefile,v 1.1 2023/04/12 11:57:49 joerg Exp $

DISTNAME=	telepath-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/telepath/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/telepath
COMMENT=	Data exchange library between Django and browser
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-django>=2.0:../../www/py-django2

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m django test --settings=telepath.test_settings

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
