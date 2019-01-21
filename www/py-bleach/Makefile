# $NetBSD: Makefile,v 1.13 2019/01/21 12:23:39 adam Exp $

DISTNAME=	bleach-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bleach/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/bleach
COMMENT=	Easy whitelist-based HTML-sanitizing tool
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.9:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-webencodings-[0-9]*:../../textproc/py-webencodings
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner>=2.0:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.0:../../devel/py-test

USE_LANGUAGES=	# none

REPLACE_SH+=	bleach/_vendor/pip_install_vendor.sh

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
