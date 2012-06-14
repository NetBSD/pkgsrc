# $NetBSD: Makefile,v 1.9 2012/06/14 07:44:45 sbd Exp $
#

DISTNAME=	rarian-0.8.1
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://rarian.freedesktop.org/Releases/
MASTER_SITES+=	${MASTER_SITE_GNOME:=sources/rarian/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rarian.freedesktop.org/
COMMENT=	Documentation metadata library
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

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
