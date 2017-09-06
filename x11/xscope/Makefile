# $NetBSD: Makefile,v 1.4 2017/09/06 09:03:06 wiz Exp $

DISTNAME=	xscope-1.4.1
CATEGORIES=	x11 devel
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/xorg/app/xscope/
COMMENT=	Tool to monitor X11/Client conversations

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
