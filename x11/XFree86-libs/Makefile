# $NetBSD: Makefile,v 1.7 2004/04/27 21:38:42 reed Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		XFree86-libs-${XF_VER}
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XFREE}
DISTFILES=		XFree86-4.4.0-src-1.tgz XFree86-4.4.0-src-2.tgz \
			XFree86-4.4.0-src-3.tgz XFree86-4.4.0-src-4.tgz

MAINTAINER=		xfree86@blef.org
HOMEPAGE=		http://www.xfree86.org/
COMMENT=		XFree86 Libraries

CONFLICTS+=		xextensions-[0-9]*
CONFLICTS+=		libX11-[0-9]*
CONFLICTS+=		libXau-[0-9]*

BUILD_DEPENDS=		imake>=4.4.0:../../x11/imake

.include "../../mk/bsd.prefs.mk"

.if ${X11ROOT} == ${LOCALBASE}
CONFLICTS+=		MesaLib-[0-9]*
.endif

USE_BUILDLINK3=			yes
BUILDLINK_PASSTHRU_DIRS+=	${X11ROOT}/lib 

XBUILD_DIRS=		lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINCLUDE_DIRS=		programs/proxymngr
XINSTALL_DIRS=		include lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINSTALL_MAN_DIRS=	${XINSTALL_DIRS}

SUBST_CLASSES=		mkstrs
SUBST_STAGE.mkstrs=	post-patch
SUBST_FILES.mkstrs=	config/cf/Library.tmpl
SUBST_SED.mkstrs=	-e 's,@MAKESTRS@,${X11ROOT}/bin/makestrs,g'
SUBST_MESSAGE.mkstrs=	"Fixing path of makestrs."

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
