# $NetBSD: Makefile,v 1.4 2008/05/24 21:45:14 tnn Exp $
#

DISTNAME=		beforelight-1.0.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Simple screen saver

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
