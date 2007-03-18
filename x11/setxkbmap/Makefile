# $NetBSD: Makefile,v 1.1.1.1 2007/03/18 19:03:26 wiz Exp $
#

DISTNAME=	setxkbmap-1.0.3
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Set the keyboard map using the X Keyboard Extension

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
