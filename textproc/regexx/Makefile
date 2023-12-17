# $NetBSD: Makefile,v 1.20 2023/12/17 19:57:26 nros Exp $
#

DISTNAME=		regexx-0.98.1
PKGREVISION=		3
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=regexx/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/regexx/
COMMENT=		C++ regular expression library

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
FORCE_CXX_STD=		c++03

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
