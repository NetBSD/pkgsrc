# $NetBSD: Makefile,v 1.1.1.1 2003/12/06 18:13:32 recht Exp $
#

DISTNAME=	gtkhtml-3.0.9
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkhtml/3.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Lightweight HTML rendering/printing/editing engine

USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/src/libgtkhtml.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/gail/buildlink2.mk"
.include "../../devel/gal2/buildlink2.mk"
.include "../../net/libsoup/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
