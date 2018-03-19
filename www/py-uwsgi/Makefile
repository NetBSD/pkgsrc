# $NetBSD: Makefile,v 1.41 2018/03/19 09:28:04 adam Exp $

.include  "Makefile.common"

LICENSE=	gnu-gpl-v2 # with linking exception
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
COMMENT=	Feature-rich WSGI server

USE_TOOLS+=	pkg-config

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}
EGG_NAME=	${DISTNAME:S/uwsgi/uWSGI/}

.include "options.mk"

INSTALL_ENV+=		UWSGI_INCLUDES=${PREFIX}/include
INSTALL_ENV+=		UWSGI_PROFILE_OVERRIDE="${UWSGI_DEBUG};${UWSGI_JSON};${UWSGI_PCRE};${UWSGI_SSL};${UWSGI_UUID};${UWSGI_XML};${UWSGI_YAML}"
INSTALLATION_DIRS+=	share/examples/${PYPKGPREFIX}-uwsgi

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} uwsgi uwsgi-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/examples/* \
		${DESTDIR}${PREFIX}/share/examples/${PYPKGPREFIX}-uwsgi

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
