# $NetBSD: Makefile,v 1.5 2005/09/07 16:49:41 reed Exp $
#

DISTNAME=		compositeext-2.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Headers and specification for X Composite extension

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	compositeext.pc.in

.include "../../x11/fixesext/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
