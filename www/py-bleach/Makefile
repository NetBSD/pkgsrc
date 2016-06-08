# $NetBSD: Makefile,v 1.4 2016/06/08 17:43:44 wiz Exp $

DISTNAME=	bleach-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bleach/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bleach
COMMENT=	Easy whitelist-based HTML-sanitizing tool
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
