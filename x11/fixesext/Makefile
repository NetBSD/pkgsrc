# $NetBSD: Makefile,v 1.4 2004/04/24 17:20:46 minskim Exp $
#

DISTNAME=		fixesext-2.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/dist/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.freedesktop.org/Software/xlibs
COMMENT=		X Fixes extension headers and specification

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_X11=		yes
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    fixesext.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
