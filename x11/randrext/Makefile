# $NetBSD: Makefile,v 1.9 2005/03/05 18:16:21 wiz Exp $

DISTNAME=		randrext-1.0
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		http://freedesktop.org/~xlibs/release/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		X RandR extension (Headers and documentation files)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    randr.pc.in

.include "../../x11/xextensions/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
