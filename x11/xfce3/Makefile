# $NetBSD: Makefile,v 1.19 2009/08/26 19:58:42 sno Exp $

DISTNAME=		xfce-3.8.18
PKGREVISION=		10
CATEGORIES=		x11
MASTER_SITES=		http://www.xfce.org/archive/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.xfce.org/
COMMENT=		Lightweight desktop environment with CDE look and feel

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes

FONTS_DIRS.x11+=	${PREFIX}/share/xfce/cursors
FONTS_DIRS.x11+=	${PREFIX}/share/xfce/fonts
REQD_DIRS+=		${PREFIX}/share/xfce
REQD_DIRS+=		${PREFIX}/share/xfce/cursors
REQD_DIRS+=		${PREFIX}/share/xfce/fonts

.if ${MACHINE_ARCH} == "alpha"
GCC_REQD+=		2.95
.endif

CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--datadir=${PREFIX:Q}/share
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX:Q}/etc
CONFIGURE_ARGS+=	--enable-imlib=${BUILDLINK_PREFIX.imlib:Q}
CONFIGURE_ARGS+=	--disable-libiconv
CONFIGURE_ARGS+=	--disable-audiofile

REPLACE_SH+=		scripts/CDE2Xfcepal other/Xclients

# work around bug in configure script
#CONFIGURE_ENV+=		gt_cv_func_gettext_libintl="yes"

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
