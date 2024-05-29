# $NetBSD: Makefile,v 1.60 2024/05/29 16:34:57 adam Exp $

DISTNAME=	vimb-3.6.0
PKGREVISION=	25
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fanglingsu/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# needed for LOCK_* macros in <fcntl.h>
LDFLAGS.SunOS+=	-lsocket -lnsl

# Bump _XOPEN_SOURCE version to 600 in order to avoid "Compiler or options
# invalid for pre-UNIX 03 X/Open applications" error on SunOS
SUBST_CLASSES+=		configmk
SUBST_STAGE.configmk=	pre-configure
SUBST_MESSAGE.configmk=	Bump _XOPEN_SOURCE version
SUBST_FILES.configmk=	config.mk
SUBST_SED.configmk+=	-e '/_XOPEN_SOURCE/ s/500/600/'

EGDIR=		${PREFIX}/share/examples/vimb

MAKE_FLAGS+=	EXAMPLEPREFIX="${DESTDIR}${EGDIR}"
MAKE_FLAGS+=	MANPREFIX="${DESTDIR}${PREFIX}/${PKGMANDIR}"
MAKE_FLAGS+=	RUNPREFIX="${PREFIX}"

REPLACE_SH+=	src/scripts/js2h.sh

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
