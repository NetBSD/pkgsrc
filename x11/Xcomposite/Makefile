# $NetBSD: Makefile,v 1.7 2005/09/07 16:49:41 reed Exp $
#

DISTNAME=		libXcomposite-1.0.1
PKGNAME=		${DISTNAME:S/lib//}
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xcomposite extension (library)

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xcomposite.pc.in

.include "../../x11/Xfixes/buildlink3.mk"
.include "../../x11/compositeext/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
