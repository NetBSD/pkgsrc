# $NetBSD: Makefile,v 1.19 2010/01/17 12:02:49 wiz Exp $

DISTNAME=	mini_httpd-1.19
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/mini_httpd/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.acme.com/software/mini_httpd/
COMMENT=	Small, forking webserver with IPv6 and SSL support

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME_NOREV}

USE_FEATURES=	snprintf

MAKE_ENV+=	PKG_CFLAGS=${CFLAGS:Q}
MAKE_ENV+=	PKG_LDFLAGS=${LDFLAGS:Q}
MAKE_ENV+=	PKG_LIBS=${LIBS:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	SYSV_LIBS="-lnsl -lsocket"
.endif

SUBST_CLASSES=		htpasswd
SUBST_MESSAGE.htpasswd=	Fix name of (m)htpasswd in manual pages.
SUBST_STAGE.htpasswd=	pre-build
SUBST_FILES.htpasswd=	htpasswd.1 mini_httpd.8
SUBST_SED.htpasswd=	-e 's/\([^.]\)htpasswd/\1mhtpasswd/g' -e 's/^htpasswd/m&/'

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
