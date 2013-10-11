# $NetBSD: Makefile,v 1.9 2013/10/11 14:33:37 obache Exp $
#

DISTNAME=	Genshi-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://ftp.edgewall.com/pub/genshi/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://genshi.edgewall.org/
COMMENT=	Python toolkit for generation of output for the web
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-babel>=0.8:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LANGUAGES=	c

# !32 for py-babel, !33 for speedups module
#PYTHON_VERSIONS_INCLUDE_3X=	yes

do-test:
		${RUN}cd ${WRKSRC};${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
