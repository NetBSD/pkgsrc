# $NetBSD: Makefile,v 1.20 2024/08/02 07:07:17 wiz Exp $

DISTNAME=		libXtst-1.2.5
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X Tst Library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xtst.pc.in

CONFIGURE_ENV+=		ac_cv_path_XMLTO=	# empty

SUBST_CLASSES+=		sofix
SUBST_SED.sofix+=	-e 's,^.so ,.so man3/,'
SUBST_FILES.sofix+=	man/XTestSetGContextOfGC.man
SUBST_FILES.sofix+=	man/XTestFakeButtonEvent.man
SUBST_FILES.sofix+=	man/XTestFakeKeyEvent.man
SUBST_FILES.sofix+=	man/XTestSetVisualIDOfVisual.man
SUBST_FILES.sofix+=	man/XTestFakeRelativeMotionEvent.man
SUBST_FILES.sofix+=	man/XTestDiscard.man
SUBST_FILES.sofix+=	man/XTestCompareCurrentCursorWithWindow.man
SUBST_FILES.sofix+=	man/XTestGrabControl.man
SUBST_FILES.sofix+=	man/XTestFakeMotionEvent.man
SUBST_FILES.sofix+=	man/XTestCompareCursorWithWindow.man
SUBST_STAGE.sofix=	post-configure
SUBST_MESSAGE.sofix=	Fix .so arguments.

X11_LIB_NAME?=		libXtst
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../meta-pkgs/modular-xorg/hacks.mk"
.include "../../x11/xorgproto/buildlink3.mk"
BUILDLINK_API_DEPENDS.libX11+=	libX11>=1.6
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXext+=		libXext>=1.0.99.4
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
