# $NetBSD: Makefile,v 1.18 2006/03/04 21:31:07 jlam Exp $
#

DISTNAME=		libXfixes-2.0.1
PKGNAME=		${DISTNAME:S/libX/X/}
PKGREVISION=		2
CATEGORIES=		x11 devel
MASTER_SITES=		http://xlibs.freedesktop.org/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		X Fixes extension of X RandR

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    xfixes.pc.in

.include "../../x11/fixesext/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
