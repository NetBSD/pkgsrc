# $NetBSD: Makefile,v 1.28 2023/01/23 08:30:02 adam Exp $

DISTNAME=		libXpm-3.5.15
CATEGORIES=		x11 graphics
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X PixMap Library from modular Xorg X11

CONFLICTS+=		xpm-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gzip pkg-config xgettext
PKGCONFIG_OVERRIDE+=	xpm.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

# Don't allow the configure script to find libintl.so or else the resulting
# libXpm will be linked against it, which is not necessary.  Instead, just
# pass down INTLLIBS in the build environment for use by the [cs]xpm
# Makefiles.
#
USE_EXPLICIT_LIBDEPS=	no
CONFIGURE_ENV+=		ac_cv_search_gettext=no
# Explicitly define path to gzip.
CONFIGURE_ENV+=		XPM_PATH_GZIP=${TOOLS_GZIP_CMD}
MAKE_ENV+=		INTLLIBS=${BUILDLINK_LDADD.gettext:Q}

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "native"
XPM_CFLAGS=	-I${X11BASE}/include
XPM_LIBS=	${COMPILER_RPATH_FLAG}${X11BASE}/lib -L${X11BASE}/lib -lX11

SXPM_CFLAGS=	-I${X11BASE}/include
SXPM_LIBS=	${COMPILER_RPATH_FLAG}${X11BASE}/lib -L${X11BASE}/lib -lXt -lXext

CONFIGURE_ARGS+=	XPM_CFLAGS=${XPM_CFLAGS:Q} \
			XPM_LIBS=${XPM_LIBS:Q} \
			SXPM_CFLAGS=${SXPM_CFLAGS:Q} \
			SXPM_LIBS=${SXPM_LIBS:Q}
.endif

X11_LIB_NAME?=		libXpm
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
