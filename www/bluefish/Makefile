# $NetBSD: Makefile,v 1.54 2005/06/25 00:48:26 kristerw Exp $

DISTNAME=	bluefish-1.0
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://pkedu.fbt.eitn.wau.nl/~olivier/downloads/	\
		ftp://bluefish.advancecreations.com/bluefish/downloads/ \
		http://bluefish.mrball.net/downloads/			\
		ftp://ftp.ratisbona.com/pub/bluefish/downloads/		\
		http://bluefish.shellhung.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://bluefish.openoffice.nl/
COMMENT=	GTK HTML editor for the experienced web designer

DEPENDS+=		weblint-[0-9]*:../../www/weblint
BUILD_USES_MSGFMT=	YES

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		find gmake grep
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-icon-path=${PREFIX}/share/pixmaps
CONFIGURE_ENV+=		EXTERNAL_GREP="${TOOLS_GREP}"
CONFIGURE_ENV+=		EXTERNAL_FIND="${TOOLS_FIND}"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
