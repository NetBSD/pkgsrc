# $NetBSD: Makefile,v 1.6 2002/02/18 15:14:44 seb Exp $
#

DISTNAME=	ratpoison-1.0.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ratpoison/}

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://ratpoison.sourceforge.net/
COMMENT=	Simple window manager with no fat library dependencies

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../mk/x11.buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
