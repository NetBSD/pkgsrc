# $NetBSD: Makefile,v 1.1 2013/05/28 02:15:35 rodent Exp $
#

DISTNAME=	xditview-1.0.3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Displays ditroff output on an X display
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
