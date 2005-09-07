# $NetBSD: Makefile,v 1.13 2005/09/07 16:49:41 reed Exp $
#

DISTNAME=		fixesext-2.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/FixesExt
COMMENT=		X Fixes extension headers and specification

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    fixesext.pc.in

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
