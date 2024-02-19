# $NetBSD: Makefile,v 1.10 2024/02/19 01:47:42 gdt Exp $
#

DISTNAME=	xvkbd-4.1
CATEGORIES=	x11
MASTER_SITES=	http://t-sato.in.coocan.jp/xvkbd/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://t-sato.in.coocan.jp/xvkbd/
COMMENT=	Virtual (graphical) keyboard program for X
LICENSE=	gnu-gpl-v2

USE_IMAKE=	yes

MAKE_FLAGS+=		SHAREDIR=${PREFIX}/share/xvkbd
INSTALL_MAKE_FLAGS+=	SHAREDIR=${PREFIX}/share/xvkbd

INSTALLATION_DIRS+=	share/xvkbd

.include "../../mk/xaw.buildlink3.mk"
BUILD_DEFS+=		XAW_TYPE
.if ${XAW_TYPE} == "standard"
SUBST_CLASSES+=		xaw
SUBST_STAGE.xaw=	pre-configure
SUBST_MESSAGE.xaw=	undefine Xaw3d
SUBST_FILES.xaw=	Imakefile
SUBST_SED.xaw=		-e 's,define XAW3D,undef XAW3D,g'

.elif ${XAW_TYPE} == "neXtaw"
BUILDLINK_TRANSFORM+=	l:Xaw3d:neXtaw
.endif

.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
