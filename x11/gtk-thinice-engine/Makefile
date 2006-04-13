# $NetBSD: Makefile,v 1.20 2006/04/13 18:23:40 jlam Exp $
#

DISTNAME=	gtk-thinice-engine-2.0.2
PKGREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-thinice-engine/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thinice.sourceforge.net/
COMMENT=	Simple, clean theme engine

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	gtk-thinice-engine-2.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
