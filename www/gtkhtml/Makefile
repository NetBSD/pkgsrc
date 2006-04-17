# $NetBSD: Makefile,v 1.50 2006/04/17 13:46:01 wiz Exp $

DISTNAME=		gtkhtml-1.1.10
PKGREVISION=		8
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtkhtml/1.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Lightweight HTML rendering/printing/editing engine

USE_X11BASE=		YES
USE_TOOLS+=		gmake msgfmt
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
BROKEN_GETTEXT_DETECTION=	yes

CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../net/soup/buildlink3.mk"
.include "../../print/gnome-print/buildlink3.mk"
.include "../../www/glibwww/buildlink3.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../x11/control-center/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
