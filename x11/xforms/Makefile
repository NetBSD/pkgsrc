# $NetBSD: Makefile,v 1.40 2002/07/26 15:21:08 wiz Exp $
#

DISTNAME=	xforms-0.9999
CATEGORIES=	x11
MASTER_SITES=	ftp://ncmir.ucsd.edu/pub/xforms/OpenSource/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://world.std.com/~xforms/
COMMENT=	Graphical user interface toolkit for X Window System

USE_IMAKE=	YES
USE_X11=	YES

MAKE_ENV=	DEPEND_DEFINES="-I${BUILDLINK_DIR}/include"
SCRIPTS_ENV=	DEPEND_DEFINES="-I${BUILDLINK_DIR}/include"

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
