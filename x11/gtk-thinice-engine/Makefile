# $NetBSD: Makefile,v 1.9 2004/04/14 16:15:30 jmmv Exp $
#

DISTNAME=	gtk-thinice-engine-2.0.2
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-thinice-engine/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://thinice.sourceforge.net/
COMMENT=	Simple, clean theme engine

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	gtk-thinice-engine-2.pc.in

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
