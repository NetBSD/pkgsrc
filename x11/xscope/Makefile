# $NetBSD: Makefile,v 1.8 2023/06/04 05:16:53 wiz Exp $

DISTNAME=	xscope-1.4.4
CATEGORIES=	x11 devel
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/xorg/app/xscope/
COMMENT=	Tool to monitor X11/Client conversations

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
