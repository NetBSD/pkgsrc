# $NetBSD: Makefile,v 1.6 2020/01/18 23:36:10 rillig Exp $

DISTNAME=	xlsatoms-1.1.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Lists the interned atoms defined on an X11 server
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libxcb/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
