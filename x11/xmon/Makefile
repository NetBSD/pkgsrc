# $NetBSD: Makefile,v 1.16 2026/06/20 11:13:44 nia Exp $
#

DISTNAME=	xmon.1.5.6
PKGNAME=	xmon-1.5.6
CATEGORIES=	x11 devel
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=devel_tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.ee.ryerson.ca/~elf/xapps/Q-XVIII.html
COMMENT=	Interactive X protocol monitor

USE_IMAKE=	YES

# This is old code that uses K&R style function definitions.
# Since an evolving C standard is likely to cause compatibility
# problems with it, we force a "known working" standard. In this
# case, the minimum bootstrap requirement, and not in strict standard
# mode to ensure no APIs are hidden.
FORCE_C_STD=	gnu99

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
