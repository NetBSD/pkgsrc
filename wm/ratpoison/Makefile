# $NetBSD: Makefile,v 1.5 2001/10/21 10:10:05 wiz Exp $
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
.include "../../mk/bsd.pkg.mk"
