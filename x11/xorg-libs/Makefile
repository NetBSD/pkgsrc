# $NetBSD: Makefile,v 1.10 2004/12/20 14:45:25 xtraeme Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		xorg-libs-${XORG_VER}
PKGREVISION=		4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG}
DISTFILES=		X11R${XORG_VER}-src1.tar.gz X11R${XORG_VER}-src2.tar.gz \
			X11R${XORG_VER}-src3.tar.gz
PATCH_SITES=		http://www.x.org/pub/X11R6.8.1/patches/
PATCHFILES=		xorg-681-CAN-2004-0914.patch

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.x.org/
COMMENT=		X.org Libraries

BUILD_DEPENDS=		xorg-imake>=${XORG_VER}:../../x11/xorg-imake

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/xorg/Makefile.common"

.if ${X11ROOT} == ${LOCALBASE}
CONFLICTS+=		MesaLib-[0-9]* glu-[0-9]*
CONFLICTS+=		xextensions-[0-9]*
CONFLICTS+=		libX11-[0-9]*
CONFLICTS+=		libXau-[0-9]*
.endif

USE_BUILDLINK3=			yes
BUILDLINK_PASSTHRU_DIRS+=	${X11ROOT}/lib

XBUILD_DIRS=		lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINSTALL_DIRS=		include lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINSTALL_MAN_DIRS=	${XINSTALL_DIRS}

SUBST_CLASSES+=		mkstrs
SUBST_STAGE.mkstrs=	post-patch
SUBST_FILES.mkstrs=	config/cf/Library.tmpl
SUBST_SED.mkstrs=	-e 's,@MAKESTRS@,${X11ROOT}/bin/makestrs,g'
SUBST_MESSAGE.mkstrs=	"Fixing path of makestrs."

.if ${OPSYS} == "Linux"
post-install:
	@${LDCONFIG} ${X11ROOT}/lib || ${TRUE}
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-2.[0-9]*)
.  if exists(/usr/include/threadlib.h)
SUBST_CLASSES+=		thr
SUBST_STAGE.thr=	post-patch
SUBST_FILES.thr=	config/cf/NetBSD.cf.in
SUBST_SED.thr=		-e 's|@@NETBSD_THREADLIB@@|-DUSE_NBSD_THREADLIB|'
SUBST_MESSAGE.thr=	"Fixes for threadlib.h."
.  else
SUBST_CLASSES+=		nada
SUBST_STAGE.nada=	post-patch
SUBST_FILES.nada=	config/cf/NetBSD.cf.in
SUBST_SED.nada=		-e 's|@@NETBSD_THREADLIB@@||'
.  endif
.endif

pre-install:
.if !exists(${X11ROOT}/lib/pkgconfig)
	${INSTALL_DATA_DIR} ${X11BASE}/lib/pkgconfig
.endif
.for f in fixesext.pc compositeext.pc
	@${SED} -e "s,@X11BASE@,${X11BASE},g"		\
		-e "s,@LOCALBASE@,${LOCALBASE},g"	\
		${FILESDIR}/${f} > ${WRKSRC}/${f}
	${INSTALL_DATA} ${WRKSRC}/${f} ${X11BASE}/lib/pkgconfig/${f}
.endfor

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
