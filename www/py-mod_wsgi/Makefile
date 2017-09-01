# $NetBSD: Makefile,v 1.11 2017/09/01 07:06:43 adam Exp $

DISTNAME=	mod_wsgi-4.5.18
PKGNAME=	${PYPKGPREFIX}-${APACHE_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mod_wsgi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.modwsgi.org/
COMMENT=	WSGI module for apache
LICENSE=	apache-2.0

PKG_APACHE_ACCEPTED=	apache22 apache24

DEPENDS+=	${PYPKGPREFIX}-mod_wsgi-metrics>=1.0.0:../../www/py-mod_wsgi-metrics

APACHE_MODULE=		yes
MESSAGE_SUBST+=		PYSITELIB=${PYSITELIB}
MESSAGE_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}

# __init__.py is the same as in mod_wsgi-metrics; remove it to avoid conflict
post-extract:
	${RM} -f ${WRKSRC}/src/__init__.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin/ && \
		${MV} mod_wsgi-express mod_wsgi-express${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
