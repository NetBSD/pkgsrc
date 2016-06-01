# $NetBSD: Makefile,v 1.5 2016/06/01 21:46:22 leot Exp $

DISTNAME=	vimb-2.11
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fanglingsu/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# needed for LOCK_* macros in <fcntl.h>

# Bump _XOPEN_SOURCE version to 600 in order to avoid "Compiler or options
# invalid for pre-UNIX 03 X/Open applications" error on SunOS and correctly
# define _POSIX_SOURCE
SUBST_CLASSES+=		configmk
SUBST_STAGE.configmk=	pre-configure
SUBST_MESSAGE.configmk=	Bump _XOPEN_SOURCE version and correctly define _POSIX_SOURCE
SUBST_FILES.configmk=	config.mk
SUBST_SED.configmk+=	-e '/_XOPEN_SOURCE/ s/500/600/'
SUBST_SED.configmk+=	-e '/_POSIX_SOURCE/ s/-DPOSIX_SOURCE/-DPOSIX_SOURCE=1/'

EGDIR=		${PREFIX}/share/examples/vimb

MAKE_ENV+=	EXAMPLEDIR="${EGDIR}" MANDIR="${PREFIX}/${PKGMANDIR}"

NOT_PAX_MPROTECT_SAFE+=	bin/vimb

.include "../../net/libsoup/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
