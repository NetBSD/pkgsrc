# $NetBSD: Makefile,v 1.1 2013/11/01 20:42:32 wiz Exp $

DISTNAME=	dri3proto-1.0
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/archive/individual/proto/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	X11 extension for Direct Rendering Infrastructure V3
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

PKGCONFIG_OVERRIDE+=	dri3proto.pc.in

.include "../../mk/bsd.pkg.mk"
