# $NetBSD: Makefile,v 1.42 2002/09/21 00:24:03 jlam Exp $
#

DISTNAME=	xforms-0.9999
CATEGORIES=	x11
MASTER_SITES=	ftp://ncmir.ucsd.edu/pub/xforms/OpenSource/
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
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
