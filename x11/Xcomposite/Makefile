# $NetBSD: Makefile,v 1.13 2006/12/15 20:33:03 joerg Exp $
#

DISTNAME=		libXcomposite-1.0.1
PKGNAME=		${DISTNAME:S/lib//}
PKGREVISION=		3
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		Xcomposite extension (library)

CONFLICTS+=		libXcomposite-[0-9]*

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	xcomposite.pc.in

.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/fixesproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
