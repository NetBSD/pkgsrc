# $NetBSD: Makefile,v 1.71 2006/12/27 13:40:42 wulf Exp $

DISTNAME=	bluefish-1.0.6
CATEGORIES=	www
MASTER_SITES=	http://bluefish.mrball.net/stable/source/               \
		ftp://ftp.ratisbona.com/pub/bluefish/stable/source/     \
		http://www.bennewitz.com/bluefish/stable/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://bluefish.openoffice.nl/
COMMENT=	GTK HTML editor for the experienced web designer

DEPENDS+=		weblint-[0-9]*:../../www/weblint

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		find gmake grep msgfmt pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-icon-path=${PREFIX:Q}/share/pixmaps
CONFIGURE_ARGS+=	--with-freedesktop_org-menu=${PREFIX:Q}/share/applications
CONFIGURE_ARGS+=	--with-freedesktop_org-mime=${PREFIX:Q}/share/mime
CONFIGURE_ARGS+=	--with-gnome2_4-mime=${PREFIX:Q}/share/mime-info
CONFIGURE_ARGS+=	--with-gnome2_4-appreg=${PREFIX:Q}/share/application-registry
CONFIGURE_ENV+=		EXTERNAL_GREP=${TOOLS_GREP:Q}
CONFIGURE_ENV+=		EXTERNAL_FIND=${TOOLS_FIND:Q}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
