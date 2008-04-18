# $NetBSD: Makefile,v 1.5 2008/04/18 12:00:13 joerg Exp $
#

DISTNAME=	rarian-0.8.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://rarian.freedesktop.org/Releases/
MASTER_SITES+=	${MASTER_SITE_GNOME:=sources/rarian/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rarian.freedesktop.org/
COMMENT=	Documentation metadata library

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	scrollkeeper-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run

CONFIGURE_ENV+=	ac_cv_path_have_bash=${TOOLS_BASH:Q}

PKGCONFIG_OVERRIDE+=	rarian.pc.in

DEPENDS+=	getopt-[0-9]*:../../misc/getopt

REQD_DIRS=	share/omf

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
