# $NetBSD: Makefile,v 1.8 2004/02/11 03:59:51 xtraeme Exp $
#

DISTNAME=	gtkhtml-3.0.9
PKGNAME=	${DISTNAME:S/gtkhtml/gtkhtml3/}
PKGREVISION=	5
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkhtml/3.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Lightweight HTML rendering/printing/editing engine

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libgtkhtml.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gal2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
