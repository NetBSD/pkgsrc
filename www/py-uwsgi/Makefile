# $NetBSD: Makefile,v 1.37 2017/07/09 10:44:19 adam Exp $

DISTNAME=	uwsgi-2.0.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.unbit.it/uwsgi
COMMENT=	Feature-rich WSGI server
LICENSE=	gnu-gpl-v2 # with linking exception

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
EGG_NAME=	${DISTNAME:S/uwsgi/uWSGI/}

.include "options.mk"

INSTALL_ENV+=		UWSGI_INCLUDES=${PREFIX}/include
INSTALL_ENV+=		UWSGI_PROFILE_OVERRIDE="${UWSGI_DEBUG}${UWSGI_JSON}${UWSGI_PCRE}${UWSGI_SSL}${UWSGI_UUID}${UWSGI_XML}${UWSGI_YAML}"
INSTALLATION_DIRS+=	share/examples/${PYPKGPREFIX}-uwsgi

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} uwsgi uwsgi-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${DESTDIR}${PREFIX}/share/examples/${PYPKGPREFIX}-uwsgi

.include "../../lang/python/egg.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
