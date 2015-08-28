# $NetBSD: Makefile,v 1.4 2015/08/28 10:34:07 wiz Exp $

DISTNAME=	gunicorn-19.3.0
PKGREVISION=	1
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

#   File "/usr/pkg/lib/python2.7/site-packages/gunicorn/workers/_gaiohttp.py", line 68
#     yield from self.wsgi.close()
#              ^
# SyntaxError: invalid syntax
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${WRKSRC}/docs/source && pax -wr -pma *.rst	\
		${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/examples && pax -wr -pma *		\
		${DESTDIR}${EXAMPLESDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
