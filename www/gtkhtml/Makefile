# $NetBSD: Makefile,v 1.25.2.1 2003/02/17 04:46:23 agc Exp $

DISTNAME=		gtkhtml-1.1.7
PKGREVISION=		1
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtkhtml/1.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Lightweight HTML rendering/printing/editing engine

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../net/soup/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../www/glibwww/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"
.include "../../x11/controlcenter/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
