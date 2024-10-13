# $NetBSD: Makefile,v 1.6 2024/10/13 07:28:23 wiz Exp $

DISTNAME=	xcmsdb-1.0.7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Loads, queries, or removes Device Color Characterization data
LICENSE=	x11 # XXX and another

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
