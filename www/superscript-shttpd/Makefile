# $NetBSD: Makefile,v 1.3 2021/12/19 10:02:11 schmonz Exp $

DISTNAME=		shttpd-0.53
PKGNAME=		superscript-${DISTNAME}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=SuperScript/shttpd/raw/179e52631ce26d2e3b6137596466b1764ba276ea/dist/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://web.archive.org/web/20120908072828/http://www.superscript.com/shttpd/index.html
COMMENT=		HTTP daemons designed to complement publicfile
#LICENSE=		# TODO: (see mk/license.mk)

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	leapsecs_read.c
SUBST_VARS.paths=	PKG_SYSCONFDIR

SUBST_CLASSES+=		djberrno
SUBST_FILES.djberrno=	error.h leapsecs_read.c

LDFLAGS.SunOS+=		-lsocket

post-configure:
	cd ${WRKSRC} && cp conf-ld conf-lds

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
