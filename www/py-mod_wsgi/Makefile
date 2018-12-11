# $NetBSD: Makefile,v 1.18 2018/12/11 09:46:23 adam Exp $

DISTNAME=	mod_wsgi-4.6.5
PKGNAME=	${PYPKGPREFIX}-${APACHE_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mod_wsgi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.modwsgi.org/
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
