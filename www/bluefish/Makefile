# $NetBSD: Makefile,v 1.169 2024/05/29 16:34:48 adam Exp $

DISTNAME=	bluefish-2.2.14
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bluefish/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bluefish.openoffice.nl/
COMMENT=	GTK HTML editor for the experienced web designer
LICENSE=	gnu-gpl-v3

DEPENDS+=		weblint-[0-9]*:../../www/weblint

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		find gmake grep msgfmt pkg-config perl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-icon-path=${PREFIX:Q}/share/pixmaps
CONFIGURE_ARGS+=	--with-freedesktop_org-menu=${PREFIX:Q}/share/applications
CONFIGURE_ARGS+=	--with-freedesktop_org-mime=${PREFIX:Q}/share/mime
CONFIGURE_ENV+=		EXTERNAL_GREP=${TOOLS_GREP:Q}
CONFIGURE_ENV+=		EXTERNAL_FIND=${TOOLS_FIND:Q}

CHECK_WRKREF_SKIP+=		lib/bluefish/about.*
REPLACE_PYTHON+=		data/lorem-ipsum-generator data/jsbeautify
REPLACE_PYTHON+=		data/cssmin.py data/jsmin.py
REPLACE_PYTHON+=		data/css_decompressor
CHECK_INTERPRETER_SKIP+=	share/bluefish/plugins/*/*.py
CHECK_INTERPRETER_SKIP+=	share/bluefish/plugins/*/*/*.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/application.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
# too new
#.include "../../fonts/gucharmap/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
