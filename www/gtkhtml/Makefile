# $NetBSD: Makefile,v 1.17 2002/01/17 11:15:32 martti Exp $

DISTNAME=		gtkhtml-1.0.1
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gtkhtml/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Lightweight HTML rendering/printing/editing engine

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../www/glibwww/buildlink.mk"
.include "../../www/libghttp/buildlink.mk"
.include "../../x11/controlcenter/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
