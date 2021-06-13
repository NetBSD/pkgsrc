# $NetBSD: Makefile,v 1.1 2021/06/13 10:25:37 nia Exp $

DISTNAME=	xrectsel-0.3.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lolilolicon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lolilolicon/xrectsel
COMMENT=	Print the geometry of a rectangular screen region
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	autoconf autoreconf automake
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
