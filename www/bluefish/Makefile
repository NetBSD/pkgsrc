# $NetBSD: Makefile,v 1.101 2012/10/02 17:12:07 tron Exp $

DISTNAME=	bluefish-2.2.3
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://bluefish.mrball.net/stable/source/               \
		http://www.bennewitz.com/bluefish/stable/source/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bluefish.openoffice.nl/
COMMENT=	GTK HTML editor for the experienced web designer

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		weblint-[0-9]*:../../www/weblint

USE_TOOLS+=		find gmake grep msgfmt pkg-config perl intltool
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-icon-path=${PREFIX:Q}/share/pixmaps
CONFIGURE_ARGS+=	--with-freedesktop_org-menu=${PREFIX:Q}/share/applications
CONFIGURE_ARGS+=	--with-freedesktop_org-mime=${PREFIX:Q}/share/mime
CONFIGURE_ENV+=		EXTERNAL_GREP=${TOOLS_GREP:Q}
CONFIGURE_ENV+=		EXTERNAL_FIND=${TOOLS_FIND:Q}

CHECK_WRKREF_SKIP+=	lib/bluefish/about.so
REPLACE_PYTHON+=	data/lorem-ipsum-generator

# XXX this doesn't work
#XML_CATALOGS=	${PREFIX}/share/xml/bluefish/catalog.xml
#XML_ENTRIES=	delegateURI http://bluefish.openoffice.nl/ns/bflang/2.0/ \
#		${PREFIX}/share/xml/bluefish/2.0/
#.include "../../textproc/xmlcatmgr/catalogs.mk"

.include "../../lang/python/application.mk"
#CONFIGURE_ARGS+=	--disable-python

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../fonts/gucharmap/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
