# $NetBSD: Makefile,v 1.1.1.1 2004/07/29 04:50:56 xtraeme Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		xorg-libs-${XORG_VER}
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG}
DISTFILES=		X11R6.7.0-src1.tar.gz X11R6.7.0-src2.tar.gz \
			X11R6.7.0-src3.tar.gz

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.x.org/
COMMENT=		X.org Libraries

CONFLICTS+=		xextensions-[0-9]*
CONFLICTS+=		libX11-[0-9]*
CONFLICTS+=		libXau-[0-9]*
CONFLICTS+=		XFree86-libs-[0-9]*

BUILD_DEPENDS=		xorg-imake>=6.7.0:../../x11/xorg-imake

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/xorg/Makefile.common"

.if ${X11ROOT} == ${LOCALBASE}
CONFLICTS+=		MesaLib-[0-9]* glu-[0-9]*
.endif

MESSAGE_SRC=		${_PKGSRCDIR}/x11/XFree86-libs/MESSAGE

USE_BUILDLINK3=			yes
BUILDLINK_PASSTHRU_DIRS+=	${X11ROOT}/lib

XBUILD_DIRS=		lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINSTALL_DIRS=		include lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINSTALL_MAN_DIRS=	${XINSTALL_DIRS}

SUBST_CLASSES=		mkstrs
SUBST_STAGE.mkstrs=	post-patch
SUBST_FILES.mkstrs=	config/cf/Library.tmpl
SUBST_SED.mkstrs=	-e 's,@MAKESTRS@,${X11ROOT}/bin/makestrs,g'
SUBST_MESSAGE.mkstrs=	"Fixing path of makestrs."

.if ${OPSYS} == "Linux"
post-install:
	@${LDCONFIG} ${X11ROOT}/lib || ${TRUE}
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
