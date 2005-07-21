# $NetBSD: Makefile,v 1.3 2005/07/21 16:29:59 wiz Exp $
#

DISTNAME=		compositeext-2.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Headers and specification for X Composite extension

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	compositeext.pc.in

.include "../../x11/fixesext/buildlink3.mk"
.include "../../x11/xextensions/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
