# $NetBSD: Makefile,v 1.1 2012/10/18 09:42:46 wiz Exp $
#

DISTNAME=	xscope-1.3.1
CATEGORIES=	x11 devel
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cgit.freedesktop.org/xorg/app/xscope/
COMMENT=	Tool to monitor X11/Client conversations

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
