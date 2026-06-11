# $NetBSD: Makefile,v 1.34 2026/06/11 13:17:07 adam Exp $

DISTNAME=	bleach-6.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bleach/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/bleach
COMMENT=	Easy whitelist-based HTML-sanitizing tool
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-webencodings-[0-9]*:../../textproc/py-webencodings

USE_LANGUAGES=	# none

REPLACE_SH+=	bleach/_vendor/vendor_install.sh

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
