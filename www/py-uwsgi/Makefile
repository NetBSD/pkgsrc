# $NetBSD: Makefile,v 1.38 2018/02/13 08:34:03 adam Exp $

DISTNAME=	uwsgi-2.0.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uwsgi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uwsgi-docs.readthedocs.io/
COMMENT=	Feature-rich WSGI server
LICENSE=	gnu-gpl-v2 # with linking exception

USE_TOOLS+=	pkg-config

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
EGG_NAME=	${DISTNAME:S/uwsgi/uWSGI/}

.include "options.mk"

INSTALL_ENV+=	UWSGI_INCLUDES=${PREFIX}/include
INSTALL_ENV+=	UWSGI_PROFILE_OVERRIDE="pcre=True;ssl=True;${UWSGI_DEBUG};${UWSGI_JSON};${UWSGI_UUID};${UWSGI_XML};${UWSGI_YAML}"

INSTALLATION_DIRS+=	share/examples/${PYPKGPREFIX}-uwsgi

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} uwsgi uwsgi-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${DESTDIR}${PREFIX}/share/examples/${PYPKGPREFIX}-uwsgi

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
