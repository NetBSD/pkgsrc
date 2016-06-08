# $NetBSD: Makefile,v 1.5 2016/06/08 17:43:48 wiz Exp $

DISTNAME=	mod_wsgi-4.4.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mod_wsgi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/modwsgi/
COMMENT=	WSGI module for apache
LICENSE=	apache-2.0

PKG_APACHE_ACCEPTED=	apache22 apache24

DEPENDS+=	${PYPKGPREFIX}-mod_wsgi-metrics>=1.0.0:../../www/py-mod_wsgi-metrics

APACHE_MODULE=		yes
MESSAGE_SUBST+=		PYSITELIB=${PYSITELIB}
MESSAGE_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}
PLIST_SUBST+=		PYPKGPREFIX=${PYPKGPREFIX}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}
FILES_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

# __init__.py is the same as in mod_wsgi-metrics; remove it to avoid conflict
post-extract:
	${RM} -f ${WRKSRC}/src/__init__.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/mod_wsgi-express \
		${DESTDIR}${PREFIX}/bin/mod_wsgi-express${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
