# $NetBSD: Makefile,v 1.68 2012/07/30 02:53:57 dholland Exp $
#

DISTNAME=	xforms-1.0
PKGREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	http://download.savannah.nongnu.org/releases/xforms/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/xforms
COMMENT=	Graphical user interface toolkit for X Window System

PKG_DESTDIR_SUPPORT=	user-destdir

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
