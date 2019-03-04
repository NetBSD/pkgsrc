# $NetBSD: Makefile,v 1.13 2019/03/04 12:04:22 adam Exp $

DISTNAME=	Genshi-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/Genshi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://genshi.edgewall.org/
COMMENT=	Python toolkit for generation of output for the web
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
