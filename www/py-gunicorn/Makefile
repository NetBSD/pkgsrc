# $NetBSD: Makefile,v 1.8 2016/10/01 14:15:04 wen Exp $

DISTNAME=	gunicorn-19.6.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gunicorn/}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://gunicorn.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	mit

# These depends is used for test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_TOOLS+=	pax

DOCDIR=		${PREFIX}/share/doc/py-gunicorn
EXAMPLESDIR=	${PREFIX}/share/examples/py-gunicorn
AUTO_MKDIRS=	yes

# https://github.com/benoitc/gunicorn/issues/1108
# according to upstream it is fine that one file does not
# compile with python-2.x because it won't be used there

post-install:
	cd ${WRKSRC}/docs/source && pax -wr -pma *.rst	\
		${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/examples && pax -wr -pma *		\
		${DESTDIR}${EXAMPLESDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
