# $NetBSD: Makefile,v 1.26 2018/11/22 09:14:42 leot Exp $

DISTNAME=	vimb-3.3.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fanglingsu/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# needed for LOCK_* macros in <fcntl.h>

EGDIR=		${PREFIX}/share/examples/vimb

MAKE_FLAGS+=	EXAMPLEPREFIX="${DESTDIR}${EGDIR}"
MAKE_FLAGS+=	MANPREFIX="${DESTDIR}${PREFIX}/${PKGMANDIR}"
MAKE_FLAGS+=	RUNPREFIX="${PREFIX}"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
