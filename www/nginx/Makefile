# $NetBSD: Makefile,v 1.3 2008/01/07 10:42:01 ghen Exp $

DISTNAME=		nginx-0.5.34
CATEGORIES=		www
MASTER_SITES=		http://sysoev.ru/nginx/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://nginx.net/
COMMENT=		Lightweight HTTP server and mail proxy server

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ld-opt=-L${PREFIX}/lib\ -Wl,-R${PREFIX}/lib
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sbin-path=${PREFIX}/sbin
CONFIGURE_ARGS+=	--conf-path=${PKG_SYSCONFDIR}/nginx.conf
CONFIGURE_ARGS+=	--pid-path=${VARBASE}/run/nginx.pid
CONFIGURE_ARGS+=	--error-log-path=${NGINX_LOGDIR}/error.log
CONFIGURE_ARGS+=	--http-log-path=${NGINX_LOGDIR}/access.log
CONFIGURE_ARGS+=	--with-mail

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	nginx
NGINX_LOGDIR?=		${VARBASE}/log/nginx

EGDIR=			${PREFIX}/share/examples/nginx
EGFILES=		fastcgi_params koi-utf koi-win mime.types nginx.conf win-utf

.for file in ${EGFILES}
CONF_FILES+=		${EGDIR:Q}/conf/${file} ${PKG_SYSCONFDIR}/${file}
.endfor

RCD_SCRIPTS=		nginx

INSTALLATION_DIRS=	sbin share/examples/nginx/conf share/examples/nginx/html
OWN_DIRS=		${NGINX_LOGDIR}

BUILD_DEFS+=		PKG_SYSCONFBASE NGINX_LOGDIR VARBASE

BUILD_TARGET=		build

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	conf/nginx.conf
SUBST_SED.paths=	-e 's,%%PKG_SYSCONFDIR%%,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,%%NGINX_LOGDIR%%,${NGINX_LOGDIR},g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objs/nginx ${DESTDIR}${PREFIX}/sbin/nginx
.for file in ${EGFILES}
	${INSTALL_DATA} ${WRKSRC}/conf/${file} ${DESTDIR}${EGDIR}/conf/${file}
.endfor
	${INSTALL_DATA} ${WRKSRC}/html/50x.html ${DESTDIR}${EGDIR}/html/50x.html
	${INSTALL_DATA} ${WRKSRC}/html/index.html ${DESTDIR}${EGDIR}/html/index.html

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
