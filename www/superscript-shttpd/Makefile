# $NetBSD: Makefile,v 1.4 2025/05/22 04:51:29 schmonz Exp $

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

FORCE_C_STD=		c89

DJB_ERRNO_FIXUP=	error.h leapsecs_read.c

LDFLAGS.SunOS+=		-lsocket

post-configure:
	cd ${WRKSRC} && cp conf-ld conf-lds

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
