# $NetBSD: Makefile,v 1.29 2024/08/10 09:28:18 wiz Exp $

DISTNAME=	bleach-6.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bleach/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/mozilla/bleach
COMMENT=	Easy whitelist-based HTML-sanitizing tool
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-webencodings-[0-9]*:../../textproc/py-webencodings

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_SH+=	bleach/_vendor/vendor_install.sh

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
