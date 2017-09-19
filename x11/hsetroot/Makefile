# $NetBSD: Makefile,v 1.25 2017/09/19 08:21:10 wiz Exp $

DISTNAME=	hsetroot-1.0.2
PKGREVISION=	14
CATEGORIES=	x11
MASTER_SITES=	http://thegraveyard.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/himdel/hsetroot
COMMENT=	Allows you to compose wallpapers for X
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-lX11

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
