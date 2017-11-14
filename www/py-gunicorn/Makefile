# $NetBSD: Makefile,v 1.11 2017/11/14 00:28:00 minskim Exp $

DISTNAME=	gunicorn-19.7.1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gunicorn/}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://gunicorn.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	mit

# These depends is used for test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov

USE_TOOLS+=	pax

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGBASE}
AUTO_MKDIRS=	yes

INSTALLATION_DIRS+=	share/doc/${PKGBASE} share/examples/${PKGBASE}

post-install:
	cd ${WRKSRC}/docs/source && pax -wr -pma *.rst	\
		${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/examples && pax -wr -pma *		\
		${DESTDIR}${EXAMPLESDIR}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} gunicorn gunicorn-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} gunicorn_paster gunicorn_paster-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
