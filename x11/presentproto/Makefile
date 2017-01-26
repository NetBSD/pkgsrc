# $NetBSD: Makefile,v 1.2 2017/01/26 08:40:32 wiz Exp $

DISTNAME=	presentproto-1.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/archive/individual/proto/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	X11 extension for efficient window updates
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	presentproto.pc.in

.include "../../mk/bsd.pkg.mk"
