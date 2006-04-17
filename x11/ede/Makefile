# $NetBSD: Makefile,v 1.5 2006/04/17 13:46:52 wiz Exp $
#

DISTNAME=	ede-1.0.4
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ede/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ede.sourceforge.net/
COMMENT=	Equinox Desktop Environment

WRKSRC=			${WRKDIR}/ede
USE_LANGUAGES+=		c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../x11/efltk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
