# $NetBSD: Makefile,v 1.11 2005/07/21 16:30:00 wiz Exp $
#

DISTNAME=		fixesext-2.0.1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/FixesExt
COMMENT=		X Fixes extension headers and specification

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    fixesext.pc.in

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
