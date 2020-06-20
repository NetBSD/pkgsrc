# $NetBSD: Makefile,v 1.20 2020/06/20 16:36:49 adam Exp $

DISTNAME=	mod_wsgi-4.7.1
PKGNAME=	${PYPKGPREFIX}-${APACHE_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mod_wsgi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://modwsgi.readthedocs.io/
COMMENT=	WSGI module for apache
LICENSE=	apache-2.0

APACHE_MODULE=		yes
MESSAGE_SUBST+=		PYSITELIB=${PYSITELIB}
MESSAGE_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} mod_wsgi-express mod_wsgi-express-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
