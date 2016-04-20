# $NetBSD: Makefile,v 1.2 2016/04/20 16:10:14 leot Exp $

DISTNAME=	h2-2.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hyper.rtfd.org/
COMMENT=	HTTP/2 State-Machine based protocol implementation
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-hyperframe>=3.1:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-hpack>=2.0:../../net/py-hpack

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
