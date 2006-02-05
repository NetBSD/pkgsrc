# $NetBSD: Makefile,v 1.55 2006/02/05 23:11:47 joerg Exp $
#

DISTNAME=	xforms-1.0-release
PKGNAME=	xforms-1.0
PKGREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	ftp://ncmir.ucsd.edu/pub/xforms/OpenSource/ \
		http://archive.cs.uu.nl/mirror/XFORMS/OpenSource/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://world.std.com/~xforms/
COMMENT=	Graphical user interface toolkit for X Window System

USE_IMAKE=	YES

MAKE_ENV=	DEPEND_DEFINES=${CPPFLAGS:M*:Q}
SCRIPTS_ENV=	DEPEND_DEFINES="${CPPFLAGS}"

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
