# $NetBSD: Makefile,v 1.26 2004/10/03 00:18:36 tv Exp $

DISTNAME=	mlterm-2.8.0
PKGNAME=	${DISTNAME}pl1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mlterm/}

PATCHFILES=	${DISTNAME}pl1.tar.gz
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://mlterm.sourceforge.net/
COMMENT=	Multilingual terminal emulator

# CODESET is only supported on NetBSD in 1.5T and later - see <langinfo.h>
ONLY_FOR_PLATFORM=	NetBSD-1.5[T-Z]-* NetBSD-1.5Z[A-Z]-*
ONLY_FOR_PLATFORM+=	NetBSD-1.6*-* NetBSD-[2-9]*-*

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-imagelib=imlib
CONFIGURE_ARGS+=	--enable-anti-alias
CONFIGURE_ARGS+=	--without-libiconv-prefix

SUBST_CLASSES+=		link
SUBST_MESSAGE.link=	"Fixing hardcoded paths and link options."
SUBST_STAGE.link=	post-patch
SUBST_FILES.link=	Makefile.in */Makefile.in \
			*/*/Makefile.in */*/*/Makefile.in \
			xwindow/x_screen.c xwindow/x_sb_view_factory.c \
			mlterm/ml_config_menu.c man/mlterm.1
SUBST_SED.link=		-e 's|-module|-R${X11BASE}/lib -module|g' \
			-e 's|\(-[R]\)/usr/local/lib||g' \
			-e 's|/usr/local/|${PREFIX}/|g' \
			-e 's|/usr/X11R6/|${X11BASE}/|g'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
