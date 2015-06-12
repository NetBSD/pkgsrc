# $NetBSD: Makefile,v 1.8 2015/06/12 10:51:41 wiz Exp $
#

DISTNAME=	hebcal-3.11
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hebcal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hebcal.sourceforge.net/
COMMENT=	Perpetual Hebrew calendar
LICENSE=	gnu-gpl-v2

INFO_FILES=	yes

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_TOOLS+=	perl
USE_TOOLS+=	m4
USE_TOOLS+=	makeinfo

.include "../../mk/bsd.pkg.mk"
