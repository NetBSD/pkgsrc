# $NetBSD: Makefile,v 1.14 2001/01/04 18:10:22 wiz Exp $

DISTNAME=		xfce-3.5.2
CATEGORIES=		x11
MASTER_SITES=		http://www.xfce.org/archive/

MAINTAINER=		jwise@netbsd.org
HOMEPAGE=		http://www.xfce.org/

BUILD_DEPENDS+=		msgfmt:../../devel/gettext
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		imlib-1.9.*:../../graphics/imlib

USE_X11=		# defined
USE_XPM=		# defined
USE_X11BASE=		# defined

USE_LIBINFO=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined

EVAL_PREFIX+=		IMLIBDIR=imlib
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ARGS+=	--enable-imlib=${IMLIBDIR}

CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

# work around bug in configure script
CONFIGURE_ENV+=		gt_cv_func_gettext_libintl="yes"

CPPFLAGS+=		-I${X11BASE}/include	# dependent includes for xpm.h

.include "../../mk/bsd.pkg.mk"
