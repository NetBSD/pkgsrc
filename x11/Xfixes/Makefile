# $NetBSD: Makefile,v 1.10 2004/08/05 22:18:38 recht Exp $
#

DISTNAME=		libXfixes-2.0.1
PKGNAME=		${DISTNAME:S/libX/X/}
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://freedesktop.org/
COMMENT=		X Fixes extension of X RandR

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_X11=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    xfixes.pc.in

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/fixesext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
