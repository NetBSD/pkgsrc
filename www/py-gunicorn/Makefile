# $NetBSD: Makefile,v 1.3 2015/08/09 18:41:58 gls Exp $

DISTNAME=	gunicorn-19.3.0
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/g/gunicorn/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://gunicorn.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	mit

USE_TOOLS+=	pax

DOCDIR=		${PREFIX}/share/doc/py-gunicorn
EXAMPLESDIR=	${PREFIX}/share/examples/py-gunicorn
AUTO_MKDIRS=	yes

post-install:
	cd ${WRKSRC}/docs/source && pax -wr -pma *.rst	\
		${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/examples && pax -wr -pma *		\
		${DESTDIR}${EXAMPLESDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
