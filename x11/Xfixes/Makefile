# $NetBSD: Makefile,v 1.14 2005/07/21 16:29:59 wiz Exp $
#

DISTNAME=		libXfixes-2.0.1
PKGNAME=		${DISTNAME:S/libX/X/}
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		X Fixes extension of X RandR

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    xfixes.pc.in

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
