# $NetBSD: Makefile,v 1.1 2009/03/05 03:18:44 smb Exp $
#

DISTNAME=	hebcal-3.7
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hebcal/}

MAINTAINER=	smb@NetBSD.org
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
