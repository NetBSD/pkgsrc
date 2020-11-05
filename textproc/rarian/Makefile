# $NetBSD: Makefile,v 1.16 2020/11/05 09:09:15 ryoon Exp $
#

DISTNAME=	rarian-0.8.1
PKGREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	https://rarian.freedesktop.org/Releases/
MASTER_SITES+=	${MASTER_SITE_GNOME:=sources/rarian/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rarian.freedesktop.org/
COMMENT=	Documentation metadata library
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

CONFLICTS+=	scrollkeeper-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run

CONFIGURE_ENV+=	ac_cv_path_have_bash=${TOOLS_BASH}

PKGCONFIG_OVERRIDE+=	rarian.pc.in

DEPENDS+=	getopt-[0-9]*:../../misc/getopt

REQD_DIRS=	share/omf

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
