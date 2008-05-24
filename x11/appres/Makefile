# $NetBSD: Makefile,v 1.2 2008/05/24 21:45:14 tnn Exp $
#

DISTNAME=		appres-1.0.1
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
