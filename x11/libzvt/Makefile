# $NetBSD: Makefile,v 1.24 2007/08/06 20:29:36 heinz Exp $
#

DISTNAME=		libzvt-2.0.1
PKGREVISION=		9
CATEGORIES=		x11 gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libzvt/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Virtual Terminal Widget Library for GNOME2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libzvt/libzvt-2.0.pc.in

.include "../../graphics/libart2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
