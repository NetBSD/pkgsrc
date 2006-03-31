# $NetBSD: Makefile,v 1.3 2006/03/31 23:26:19 reed Exp $

DISTNAME=		renderext-0.9
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://xlibs.freedesktop.org/release/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pdx.freedesktop.org/software/fontconfig/releases/
COMMENT=		Headers for X11 render extension

CONFLICTS+=		Xrender<0.8 render-[0-9]* renderproto-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	render.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
