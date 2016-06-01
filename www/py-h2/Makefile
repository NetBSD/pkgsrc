# $NetBSD: Makefile,v 1.3 2016/06/01 12:35:13 wiz Exp $

DISTNAME=	h2-2.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=h/h2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hyper.rtfd.org/
COMMENT=	HTTP/2 State-Machine based protocol implementation
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-hyperframe>=3.1:../../www/py-hyperframe
DEPENDS+=	${PYPKGPREFIX}-hpack>=2.0:../../net/py-hpack

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
