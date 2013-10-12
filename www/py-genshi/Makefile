# $NetBSD: Makefile,v 1.7.8.1 2013/10/12 14:14:59 tron Exp $
#

DISTNAME=	Genshi-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://ftp.edgewall.com/pub/genshi/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://genshi.edgewall.org/
COMMENT=	Python toolkit for generation of output for the web
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LANGUAGES=	# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
