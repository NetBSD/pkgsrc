# $NetBSD: Makefile,v 1.17 2020/05/17 20:18:35 adam Exp $

DISTNAME=	bleach-3.1.5
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

USE_LANGUAGES=	# none

REPLACE_SH+=	bleach/_vendor/pip_install_vendor.sh

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
