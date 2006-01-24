# $NetBSD: Makefile,v 1.46 2006/01/24 07:32:48 wiz Exp $

DISTNAME=		gtkhtml-1.1.10
PKGREVISION=		6
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtkhtml/1.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Lightweight HTML rendering/printing/editing engine

USE_X11BASE=		YES
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
BUILD_USES_MSGFMT=	yes

CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../net/soup/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../www/glibwww/buildlink3.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../x11/control-center/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
