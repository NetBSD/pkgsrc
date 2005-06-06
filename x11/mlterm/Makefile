# $NetBSD: Makefile,v 1.33 2005/06/06 17:25:57 hira Exp $

DISTNAME=	mlterm-2.9.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mlterm/}

MAINTAINER=	uebayasi@NetBSD.org,hira@NetBSD.org
HOMEPAGE=	http://mlterm.sourceforge.net/
COMMENT=	Multilingual terminal emulator

# CODESET is only supported on NetBSD in 1.5T and later - see <langinfo.h>
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-* NetBSD-1.5[A-S]-*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

USE_PKGLOCALEDIR=	yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-imagelib=gdk-pixbuf
CONFIGURE_ARGS+=	--with-type-engines=xft
CONFIGURE_ARGS+=	--without-libiconv-prefix
CONFIGURE_ARGS+=	--without-libintl-prefix

SUBST_CLASSES+=		link
SUBST_MESSAGE.link=	"Fixing hardcoded paths and link options."
SUBST_STAGE.link=	post-patch
SUBST_FILES.link=	Makefile.in */Makefile.in */*/Makefile.in \
			*/*/*/Makefile.in man/mlterm.1 \
			mlterm/ml_config_menu.c script/config.rpath \
			tool/mlconfig/mc_im.c tool/mlconfig/mc_sb_view.c \
			tool/mlmenu/main.c xwindow/x_im.c \
			xwindow/x_sb_view_factory.c xwindow/x_screen.c
SUBST_SED.link=		-e 's|(LIBTOOL_LINK).*(LIBS)|& -R${X11BASE}/lib|g' \
			-e 's|(LIBTOOL_LINK).*(LIBDIR)|& -R${X11BASE}/lib|g' \
			-e 's|/usr/local/|${PREFIX}/|g' \
			-e 's|/usr/X11R6/|${X11BASE}/|g'

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
