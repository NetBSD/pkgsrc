# $NetBSD: Makefile,v 1.30 2006/09/16 08:28:36 adrianp Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		XFree86-libs-${XF_VER}
PKGREVISION=		9
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XFREE}
DISTFILES=		XFree86-${XF_VER}-src-1.tgz XFree86-${XF_VER}-src-2.tgz \
			XFree86-${XF_VER}-src-3.tgz XFree86-${XF_VER}-src-4.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.xfree86.org/
COMMENT=		XFree86 Libraries

CONFLICTS+=		xextensions-[0-9]*
CONFLICTS+=		libX11-[0-9]*
CONFLICTS+=		libXau-[0-9]*

BUILD_DEPENDS+=		XFree86-imake>=${XF_VER}:../../x11/XFree86-imake

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/XFree86/Makefile.common"

.if ${X11ROOT} == ${LOCALBASE}
CONFLICTS+=		MesaLib-[0-9]* glu-[0-9]*
.endif

BUILDLINK_PASSTHRU_DIRS+=	${X11ROOT}/lib

XBUILD_DIRS=		lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINCLUDE_DIRS=		programs/proxymngr
XINSTALL_DIRS=		include lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINSTALL_MAN_DIRS=	${XINSTALL_DIRS}

SUBST_CLASSES+=		mkstrs
SUBST_STAGE.mkstrs=	post-patch
SUBST_FILES.mkstrs=	config/cf/Library.tmpl
SUBST_SED.mkstrs=	-e 's,@MAKESTRS@,${X11ROOT}/bin/makestrs,g'
SUBST_MESSAGE.mkstrs=	Fixing path of makestrs.

.if ${OPSYS} == "Linux"
post-install:
	@${LDCONFIG} ${X11ROOT}/lib || ${TRUE}
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
