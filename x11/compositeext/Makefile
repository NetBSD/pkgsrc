# $NetBSD: Makefile,v 1.8 2006/03/31 23:43:32 reed Exp $
#

DISTNAME=		compositeext-2.0
PKGREVISION=		2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Headers and specification for X Composite extension

CONFLICTS+=		compositeproto-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	compositeext.pc.in

.include "../../x11/fixesext/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
