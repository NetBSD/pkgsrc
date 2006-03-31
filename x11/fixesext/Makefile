# $NetBSD: Makefile,v 1.16 2006/03/31 23:29:28 reed Exp $
#

DISTNAME=		fixesext-2.0.1
PKGREVISION=		2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/FixesExt
COMMENT=		X Fixes extension headers and specification

CONFLICTS+=		fixesproto-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    fixesext.pc.in

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
