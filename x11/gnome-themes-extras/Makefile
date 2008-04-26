# $NetBSD: Makefile,v 1.36 2008/04/26 00:49:51 wiz Exp $
#

DISTNAME=	gnome-themes-extras-2.22.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-themes-extras/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Collection of metathemes for the GNOME desktop environment

.include "../../mk/bsd.prefs.mk"
# NetBSD's pax-as-tar truncates filenames
.if ${OPSYS} == "DragonFly"
# and so does older GNU tar
TOOLS_PLATFORM.gtar=	/usr/bin/bsdtar
.endif
EXTRACT_USING=		gtar

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED
BUILDLINK_TRANSFORM+=	rm:-DGTK_DISABLE_DEPRECATED

BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.12.6

.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2-engines/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
