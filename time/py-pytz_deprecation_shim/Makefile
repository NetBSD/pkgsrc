# $NetBSD: Makefile,v 1.4 2025/04/14 08:49:20 adam Exp $

DISTNAME=	pytz_deprecation_shim-0.1.0.post0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/post//}
PKGREVISION=	2
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytz_deprecation_shim/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pganssle/pytz-deprecation-shim
COMMENT=	Shims to make deprecation of pytz easier
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

# testing needs 'make install'

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
