# $NetBSD: Makefile,v 1.22 2012/10/23 10:24:23 wiz Exp $

DISTNAME=	xteddy-1.1
PKGREVISION=	1
CATEGORIES=	x11 games
MASTER_SITES=	http://staffwww.itn.liu.se/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://staffwww.itn.liu.se/~stegu/xteddy/
COMMENT=	Cuddly teddy bear for your desktop

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	share/xteddy/pixmaps

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
