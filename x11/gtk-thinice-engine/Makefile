# $NetBSD: Makefile,v 1.12 2004/10/03 00:18:33 tv Exp $
#

DISTNAME=	gtk-thinice-engine-2.0.2
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-thinice-engine/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://thinice.sourceforge.net/
COMMENT=	Simple, clean theme engine

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	gtk-thinice-engine-2.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
