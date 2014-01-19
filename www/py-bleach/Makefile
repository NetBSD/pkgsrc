# $NetBSD: Makefile,v 1.3 2014/01/19 18:51:18 wiz Exp $

DISTNAME=	bleach-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/b/bleach/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/bleach
COMMENT=	Easy whitelist-based HTML-sanitizing tool
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
