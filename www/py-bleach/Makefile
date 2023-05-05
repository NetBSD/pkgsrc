# $NetBSD: Makefile,v 1.27 2023/05/05 15:46:44 wiz Exp $

DISTNAME=	bleach-6.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bleach/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/bleach
COMMENT=	Easy whitelist-based HTML-sanitizing tool
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-webencodings-[0-9]*:../../textproc/py-webencodings
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner>=2.0:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_SH+=	bleach/_vendor/vendor_install.sh

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
