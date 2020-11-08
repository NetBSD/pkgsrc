# $NetBSD: Makefile,v 1.21 2020/11/08 15:25:58 kim Exp $

DISTNAME=	xclip-0.13
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=astrand/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/astrand/xclip
COMMENT=	Command line interface to the X windows clipboard
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf gmake

LDFLAGS.SunOS+=	-liconv

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
