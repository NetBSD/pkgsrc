# $NetBSD: Makefile,v 1.15 2001/10/23 13:15:06 jlam Exp $

DISTNAME=		gtkhtml-0.14.0
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gtkhtml/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		lightweight HTML rendering/printing/editing engine

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/x11.buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../print/gnome-print/buildlink.mk"
.include "../../www/glibwww/buildlink.mk"
.include "../../www/libghttp/buildlink.mk"
.include "../../x11/controlcenter/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
