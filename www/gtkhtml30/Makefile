# $NetBSD: Makefile,v 1.10 2006/01/24 07:32:48 wiz Exp $
#

DISTNAME=	gtkhtml-3.0.10
PKGNAME=	${DISTNAME:S/gtkhtml/gtkhtml30/}
PKGREVISION=	5
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkhtml/3.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Lightweight HTML rendering/printing/editing engine

USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	src/libgtkhtml.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gal20/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
