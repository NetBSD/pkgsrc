# $NetBSD: Makefile,v 1.38 2003/09/17 19:41:25 grant Exp $

DISTNAME=		xfce-3.8.18
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		http://www.xfce.org/archive/

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.xfce.org/
COMMENT=		Lightweight desktop environment with CDE look and feel

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
USE_PKGLOCALEDIR=	# defined

USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined

.if ${MACHINE_ARCH} == "alpha"
USE_PKGSRC_GCC=		# defined
.endif

CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ARGS+=	--enable-imlib=${BUILDLINK_PREFIX.imlib}
CONFIGURE_ARGS+=	--disable-libiconv
CONFIGURE_ARGS+=	--disable-audiofile

# work around bug in configure script
#CONFIGURE_ENV+=		gt_cv_func_gettext_libintl="yes"

CPPFLAGS+=		-I${X11BASE}/include	# dependent includes for xpm.h

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
