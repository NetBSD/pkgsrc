# $NetBSD: Makefile,v 1.71 2020/01/18 23:36:08 rillig Exp $
#

DISTNAME=	xforms-1.0
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	http://download.savannah.nongnu.org/releases/xforms/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/xforms
COMMENT=	Graphical user interface toolkit for X Window System

USE_IMAKE=	YES

MAKE_JOBS_SAFE=	no
MAKE_ENV+=	DEPEND_DEFINES=${CPPFLAGS:M*:Q}
MAKE_FLAGS+=	MANPATH=${PREFIX}/${PKGMANDIR}
SCRIPTS_ENV+=	DEPEND_DEFINES=${CPPFLAGS:Q}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
