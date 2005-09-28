# $NetBSD: Makefile,v 1.6 2005/09/28 20:52:28 rillig Exp $

DISTNAME=		xfce-3.8.18
PKGREVISION=		5
CATEGORIES=		x11
MASTER_SITES=		http://www.xfce.org/archive/

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.xfce.org/
COMMENT=		Lightweight desktop environment with CDE look and feel

BUILD_USES_MSGFMT=	yes

USE_X11BASE=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.if ${MACHINE_ARCH} == "alpha"
GCC_REQD+=		2.95
.endif

CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ARGS+=	--enable-imlib=${BUILDLINK_PREFIX.imlib}
CONFIGURE_ARGS+=	--disable-libiconv
CONFIGURE_ARGS+=	--disable-audiofile

# work around bug in configure script
#CONFIGURE_ENV+=		gt_cv_func_gettext_libintl="yes"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
