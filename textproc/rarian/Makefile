# $NetBSD: Makefile,v 1.1.1.1 2007/10/11 18:43:48 drochner Exp $
#

DISTNAME=	rarian-0.6.0
CATEGORIES=	textproc
MASTER_SITES=	http://rarian.freedesktop.org/Releases/
MASTER_SITES+=	${MASTER_SITE_GNOME:=sources/rarian/0.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rarian.freedesktop.org/
COMMENT=	Documentation metadata library

CONFLICTS+=	scrollkeeper-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	rarian.pc.in

DEPENDS+=	getopt-[0-9]*:../../misc/getopt
DEPENDS+=	bash-[0-9]*:../../shells/bash

# we don't install anything here, but dependent pkgs do,
# so we are the only instance which can reasonably own that dir
post-install:
	${MKDIR} ${PREFIX}/share/omf

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
