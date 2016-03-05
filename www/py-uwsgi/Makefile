# $NetBSD: Makefile,v 1.32 2016/03/05 11:29:39 jperkin Exp $

DISTNAME=	uwsgi-2.0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	python www
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.unbit.it/uwsgi
COMMENT=	Feature-rich WSGI server
LICENSE=	gnu-gpl-v2 # with linking exception

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX} PYVERSSUFFIX=${PYVERSSUFFIX}
EGG_NAME=	${DISTNAME:S/uwsgi/uWSGI/}

.include "options.mk"

INSTALL_ENV+=		UWSGI_INCLUDES=${PREFIX}/include
INSTALL_ENV+=		UWSGI_PROFILE_OVERRIDE="${UWSGI_DEBUG}${UWSGI_JSON}${UWSGI_PCRE}${UWSGI_SSL}${UWSGI_UUID}${UWSGI_XML}${UWSGI_YAML}"
INSTALLATION_DIRS+=	share/examples/${PYPKGPREFIX}-uwsgi

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/uwsgi \
		${DESTDIR}${PREFIX}/bin/uwsgi-${PYVERSSUFFIX}
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${DESTDIR}${PREFIX}/share/examples/${PYPKGPREFIX}-uwsgi

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
