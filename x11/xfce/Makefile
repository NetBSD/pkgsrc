# $NetBSD: Makefile,v 1.22 2002/02/15 09:05:01 martti Exp $

DISTNAME=		xfce-3.8.14
CATEGORIES=		x11
MASTER_SITES=		http://www.xfce.org/archive/

MAINTAINER=		jwise@netbsd.org
HOMEPAGE=		http://www.xfce.org/
COMMENT=		Lightweight desktop environment with a look and feel similar to CDE

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		imlib-1.9.*:../../graphics/imlib

GCC_VERSION!=		gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs) && (${MACHINE_ARCH} == alpha)
.include "../../lang/gcc/Makefile.gcc"
.endif

USE_X11=		# defined
USE_XPM=		# defined
USE_X11BASE=		# defined

USE_LIBINTL=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined

EVAL_PREFIX+=		IMLIBDIR=imlib
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
CONFIGURE_ARGS+=	--enable-imlib=${IMLIBDIR}

# work around bug in configure script
CONFIGURE_ENV+=		gt_cv_func_gettext_libintl="yes"

CPPFLAGS+=		-I${X11BASE}/include	# dependent includes for xpm.h

.include "../../mk/bsd.pkg.mk"
