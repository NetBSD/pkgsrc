# $NetBSD: Makefile,v 1.24 2018/11/14 22:22:37 kleink Exp $

DISTNAME=	vimb-2.12
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fanglingsu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# needed for LOCK_* macros in <fcntl.h>
LDFLAGS.SunOS+=	-lsocket -lnsl

# Bump _XOPEN_SOURCE version to 600 in order to avoid "Compiler or options
# invalid for pre-UNIX 03 X/Open applications" error on SunOS and correctly
# define _POSIX_SOURCE
SUBST_CLASSES+=		configmk
SUBST_STAGE.configmk=	pre-configure
SUBST_MESSAGE.configmk=	Bump _XOPEN_SOURCE version and correctly define _POSIX_SOURCE
SUBST_FILES.configmk=	config.mk
SUBST_SED.configmk+=	-e '/_XOPEN_SOURCE/ s/500/600/'
SUBST_SED.configmk+=	-e '/_POSIX_SOURCE/ s/-D_POSIX_SOURCE/-D_POSIX_SOURCE=1/'

EGDIR=		${PREFIX}/share/examples/vimb

MAKE_ENV+=	EXAMPLEDIR="${EGDIR}" MANDIR="${PREFIX}/${PKGMANDIR}"

NOT_PAX_MPROTECT_SAFE+=	bin/vimb

.include "../../net/libsoup/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
