# $NetBSD: Makefile,v 1.14 2015/05/09 01:37:12 mef Exp $
#

DISTNAME=	xmon.1.5.6
PKGNAME=	xmon-1.5.6
CATEGORIES=	x11 devel
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=devel_tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ee.ryerson.ca/~elf/xapps/Q-XVIII.html
COMMENT=	Interactive X protocol monitor

USE_IMAKE=	YES

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
