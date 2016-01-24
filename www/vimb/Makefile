# $NetBSD: Makefile,v 1.1 2016/01/24 17:08:39 leot Exp $

DISTNAME=	vimb-2.11
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=fanglingsu/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://fanglingsu.github.io/vimb/
COMMENT=	Vim-like webkit browser
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# needed for LOCK_* macros in <fcntl.h>

EGDIR=		${PREFIX}/share/examples/vimb

MAKE_ENV+=	EXAMPLEDIR="${EGDIR}" MANDIR="${PREFIX}/${PKGMANDIR}"

.include "../../net/libsoup/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
