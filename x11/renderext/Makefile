# $NetBSD: Makefile,v 1.2 2006/03/04 21:31:11 jlam Exp $

DISTNAME=		renderext-0.9
CATEGORIES=		x11
MASTER_SITES=		http://xlibs.freedesktop.org/release/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pdx.freedesktop.org/software/fontconfig/releases/
COMMENT=		Headers for X11 render extension

CONFLICTS=		Xrender<0.8 render-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	render.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
