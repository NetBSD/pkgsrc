# $NetBSD: Makefile,v 1.19 2013/01/26 21:39:05 adam Exp $
#

DISTNAME=	ede-1.0.4
PKGREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ede/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://equinox-project.org/
COMMENT=	Equinox Desktop Environment
LICENSE=	gnu-gpl-v2 # or later

WRKSRC=			${WRKDIR}/ede
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	bin

.include "../../x11/efltk/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
