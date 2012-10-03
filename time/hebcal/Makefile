# $NetBSD: Makefile,v 1.3 2012/10/03 21:58:17 wiz Exp $
#

DISTNAME=	hebcal-3.7
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hebcal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hebcal.sourceforge.net/
COMMENT=	Perpetual Hebrew calendar

PKG_DESTDIR_SUPPORT=	user-destdir

INFO_FILES=	yes

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_TOOLS+=	perl
USE_TOOLS+=	m4
USE_TOOLS+=	makeinfo

.include "../../mk/bsd.pkg.mk"
