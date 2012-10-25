# $NetBSD: Makefile,v 1.18 2012/10/25 06:56:54 asau Exp $
#

DISTNAME=		regexx-0.98.1
PKGREVISION=		3
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=regexx/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/regexx/
COMMENT=		C++ regular expression library

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
