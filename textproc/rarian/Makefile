# $NetBSD: Makefile,v 1.3 2007/11/28 09:18:57 tron Exp $
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
USE_TOOLS+=	bash:run

CONFIGURE_ENV+=	ac_cv_path_have_bash=${TOOLS_BASH:Q}

PKGCONFIG_OVERRIDE+=	rarian.pc.in

DEPENDS+=	getopt-[0-9]*:../../misc/getopt

# we don't install anything here, but dependent pkgs do,
# so we are the only instance which can reasonably own that dir
post-install:
	${MKDIR} ${PREFIX}/share/omf

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
