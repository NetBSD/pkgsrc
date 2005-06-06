# $NetBSD: Makefile,v 1.12 2005/06/06 19:27:57 jlam Exp $
#

DISTNAME=		libXrandr-1.0.2
PKGNAME=		Xrandr-1.0.2
PKGREVISION=		2
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X RandR extension (Library)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    xrandr.pc.in

BUILDLINK_DEPENDS.Xrender+=	Xrender>=0.8
BUILDLINK_DEPENDS.randrext+=	randrext>=1.0

.include "../../x11/Xrender/buildlink3.mk"
.include "../../x11/randrext/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
