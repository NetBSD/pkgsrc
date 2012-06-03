# $NetBSD: Makefile,v 1.6 2012/06/03 17:58:04 wiz Exp $
#

DISTNAME=		listres-1.0.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		List resources in widgets
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
