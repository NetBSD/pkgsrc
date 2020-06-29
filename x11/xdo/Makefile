# $NetBSD: Makefile,v 1.1 2020/06/29 18:35:14 pin Exp $

DISTNAME=	xdo-0.5.7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=baskerville/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/baskerville/xdo/
COMMENT=	Small X utility to perform elementary actions on windows
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake
USE_LANGUAGES=	c99

MAKE_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

# For some reason, not equivalent to  _POSIX_C_SOURCE = 200809L for the purpose of SA_RESTART.
CFLAGS.NetBSD+=	-D_XOPEN_SOURCE=700

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
