# $NetBSD: Makefile,v 1.5 2016/12/15 11:21:18 adam Exp $

DISTNAME=	bleach-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bleach/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bleach
COMMENT=	Easy whitelist-based HTML-sanitizing tool
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
