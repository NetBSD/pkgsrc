# $NetBSD: Makefile,v 1.18 2022/04/27 11:52:50 adam Exp $

DISTNAME=	Genshi-0.7.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/Genshi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://genshi.edgewall.org/
COMMENT=	Python toolkit for generation of output for the web
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
