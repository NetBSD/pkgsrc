# $NetBSD: Makefile,v 1.31 2024/11/11 07:29:16 wiz Exp $

DISTNAME=	bleach-6.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bleach/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/bleach
COMMENT=	Easy whitelist-based HTML-sanitizing tool
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-webencodings-[0-9]*:../../textproc/py-webencodings

USE_LANGUAGES=	# none

REPLACE_SH+=	bleach/_vendor/vendor_install.sh

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
