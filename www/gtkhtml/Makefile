# $NetBSD: Makefile,v 1.23 2002/12/24 06:10:28 wiz Exp $

DISTNAME=		gtkhtml-1.0.1
PKGREVISION=		3
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gtkhtml/1.0/}
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

.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../print/gnome-print/buildlink2.mk"
.include "../../www/glibwww/buildlink2.mk"
.include "../../www/libghttp/buildlink2.mk"
.include "../../x11/controlcenter/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
