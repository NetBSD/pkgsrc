# $NetBSD: Makefile,v 1.11 2018/10/26 09:11:54 adam Exp $

DISTNAME=	bleach-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bleach/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/bleach
COMMENT=	Easy whitelist-based HTML-sanitizing tool
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-webencodings-[0-9]*:../../textproc/py-webencodings
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner>=2.0:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.0.0:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
