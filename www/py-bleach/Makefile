# $NetBSD: Makefile,v 1.25 2023/04/30 18:45:35 wiz Exp $

DISTNAME=	bleach-3.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bleach/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/bleach
COMMENT=	Easy whitelist-based HTML-sanitizing tool
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-webencodings-[0-9]*:../../textproc/py-webencodings
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner>=2.0:../../devel/py-test-runner

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

REPLACE_SH+=	bleach/_vendor/pip_install_vendor.sh

PYSETUPTESTTARGET=	pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
