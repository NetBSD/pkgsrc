# $NetBSD: Makefile,v 1.5 2005/07/21 16:29:59 wiz Exp $
#

DISTNAME=		libXcomposite-1.0.1
PKGNAME=		${DISTNAME:S/lib//}
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xcomposite extension (library)

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xcomposite.pc.in

.include "../../x11/Xfixes/buildlink3.mk"
.include "../../x11/compositeext/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
