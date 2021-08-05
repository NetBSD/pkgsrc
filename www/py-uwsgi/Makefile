# $NetBSD: Makefile,v 1.48 2021/08/05 13:22:30 adam Exp $

DISTNAME=	uWSGI-2.0.19.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uWSGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uwsgi-docs.readthedocs.io/
COMMENT=	Feature-rich WSGI server
LICENSE=	gnu-gpl-v2 # with linking exception

EXTRACT_DIR=	${WRKSRC}

USE_TOOLS+=	pkg-config

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
EGG_NAME=	${DISTNAME:S/uwsgi/uWSGI/}

.include "options.mk"

INSTALL_ENV+=		UWSGI_INCLUDES=${PREFIX}/include
INSTALL_ENV+=		UWSGI_PROFILE_OVERRIDE="${UWSGI_DEBUG};${UWSGI_JSON};${UWSGI_PCRE};${UWSGI_SSE};${UWSGI_SSL};${UWSGI_UUID};${UWSGI_XML};${UWSGI_YAML}"
INSTALLATION_DIRS+=	share/examples/${PYPKGPREFIX}-uwsgi

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} uwsgi uwsgi-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${DESTDIR}${PREFIX}/share/examples/${PYPKGPREFIX}-uwsgi

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
