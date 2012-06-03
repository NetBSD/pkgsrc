# $NetBSD: Makefile,v 1.4 2012/06/03 17:53:08 wiz Exp $
#

DISTNAME=		appres-1.0.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Print resources seen by an application

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
