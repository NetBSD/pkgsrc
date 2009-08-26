# $NetBSD: Makefile,v 1.9 2009/08/26 19:58:29 sno Exp $
#

DISTNAME=	ede-1.0.4
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ede/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ede.sourceforge.net/
COMMENT=	Equinox Desktop Environment

WRKSRC=			${WRKDIR}/ede
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes

.include "../../x11/efltk/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
