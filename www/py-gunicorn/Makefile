# $NetBSD: Makefile,v 1.1 2014/05/08 09:05:51 imil Exp $

DISTNAME=	gunicorn-18.0
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/g/gunicorn/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

USE_TOOLS+=	pax
MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://gunicorn.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	mit

USE_TOOLS+=	pax

DOCDIR=		${PREFIX}/share/doc/py-gunicorn
EXAMPLESDIR=	${PREFIX}/share/examples/py-gunicorn

post-install:
	cd ${WRKSRC}/docs/source && pax -wr -pma *.rst	\
		${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/examples && pax -wr -pma *		\
		${DESTDIR}${EXAMPLESDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
