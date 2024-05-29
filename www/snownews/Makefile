# $NetBSD: Makefile,v 1.76 2024/05/29 16:34:56 adam Exp $

DISTNAME=	snownews-1.9
PKGREVISION=	9
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=msharov/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/msharov/snownews
COMMENT=	Small, curses based RSS feed reader
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake msgfmt pkg-config
HAS_CONFIGURE=	yes
FAKE_NCURSES=	yes
USE_CURSES=	wide

# PATH_MAX not visible with strict C11
FORCE_C_STD=	gnu11

LDFLAGS+=		${BUILDLINK_LDADD.curses}
LDFLAGS+=		${BUILDLINK_LDADD.gettext}
CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
