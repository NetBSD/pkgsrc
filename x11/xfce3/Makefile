# $NetBSD: Makefile,v 1.2 2004/10/03 00:18:39 tv Exp $

DISTNAME=		xfce-3.8.18
PKGREVISION=		4
CATEGORIES=		x11
MASTER_SITES=		http://www.xfce.org/archive/

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.xfce.org/
COMMENT=		Lightweight desktop environment with CDE look and feel

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_X11BASE=		# defined
USE_PKGLOCALEDIR=	# defined
USE_LIBTOOL=		# defined

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		# defined

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
