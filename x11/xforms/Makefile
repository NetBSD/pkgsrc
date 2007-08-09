# $NetBSD: Makefile,v 1.60 2007/08/09 09:40:36 tron Exp $
#

DISTNAME=	xforms-1.0-release
PKGNAME=	xforms-1.0
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	ftp://ncmir.ucsd.edu/pub/xforms/OpenSource/ \
		http://archive.cs.uu.nl/mirror/XFORMS/OpenSource/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/xforms
COMMENT=	Graphical user interface toolkit for X Window System

USE_IMAKE=	YES

MAKE_ENV=	DEPEND_DEFINES=${CPPFLAGS:M*:Q}
MAKE_FLAGS+=	MANPATH=${PREFIX}/${PKGMANDIR}
SCRIPTS_ENV=	DEPEND_DEFINES="${CPPFLAGS}"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
