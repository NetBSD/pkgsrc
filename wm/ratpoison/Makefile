# $NetBSD: Makefile,v 1.4 2001/08/29 22:41:25 jlam Exp $
#

DISTNAME=	ratpoison-0.1.1
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ratpoison/}

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://ratpoison.sourceforge.net/
COMMENT=	Simple window manager with no fat library dependencies

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
