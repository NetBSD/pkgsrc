# $NetBSD: Makefile,v 1.43 2002/12/28 19:49:07 jschauma Exp $
#

DISTNAME=	xforms-1.0-release
PKGNAME=	xforms-1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ncmir.ucsd.edu/pub/xforms/OpenSource/ \
		http://archive.cs.uu.nl/mirror/XFORMS/OpenSource/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://world.std.com/~xforms/
COMMENT=	Graphical user interface toolkit for X Window System

USE_BUILDLINK2=	YES
USE_IMAKE=	YES
USE_X11=	YES

MAKE_ENV=	DEPEND_DEFINES="${CPPFLAGS}"
SCRIPTS_ENV=	DEPEND_DEFINES="${CPPFLAGS}"

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
