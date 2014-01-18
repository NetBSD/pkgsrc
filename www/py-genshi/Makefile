# $NetBSD: Makefile,v 1.10 2014/01/18 07:40:24 wiz Exp $

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

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} == "py33"
PLIST_SRC+=	PLIST PLIST.py3
.else
PLIST_SRC+=	PLIST PLIST.py2
.endif

do-test:
		${RUN}cd ${WRKSRC};${PYTHONBIN} setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
