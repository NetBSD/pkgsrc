# $NetBSD: Makefile,v 1.19 2016/11/16 15:29:35 leot Exp $

DISTNAME=	xclip-0.13
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=astrand/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astrand/xclip
COMMENT=	Command line interface to the X windows clipboard
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
