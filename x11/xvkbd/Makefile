# $NetBSD: Makefile,v 1.9 2015/10/14 20:17:28 wiz Exp $
#

DISTNAME=	xvkbd-3.5
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://homepage3.nifty.com/tsato/xvkbd/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://homepage3.nifty.com/tsato/xvkbd/
COMMENT=	The xvkbd is a virtual (graphical) keyboard program for X
LICENSE=	gnu-gpl-v2

USE_IMAKE=	yes

.include "../../mk/xaw.buildlink3.mk"
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
