# $NetBSD: Makefile,v 1.22 2022/08/09 12:08:35 jperkin Exp $

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

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
