# $NetBSD: Makefile,v 1.57 2006/10/18 21:36:03 rillig Exp $
#

DISTNAME=	xforms-1.0-release
PKGNAME=	xforms-1.0
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	ftp://ncmir.ucsd.edu/pub/xforms/OpenSource/ \
		http://archive.cs.uu.nl/mirror/XFORMS/OpenSource/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://world.std.com/~xforms/
COMMENT=	Graphical user interface toolkit for X Window System

USE_IMAKE=	YES

MAKE_ENV=	DEPEND_DEFINES=${CPPFLAGS:M*:Q}
MAKE_FLAGS+=	MANPATH=${PREFIX}/${PKGMANDIR}
SCRIPTS_ENV=	DEPEND_DEFINES="${CPPFLAGS}"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
