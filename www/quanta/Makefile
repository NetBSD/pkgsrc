# $NetBSD: Makefile,v 1.2 2001/03/28 21:47:37 hubertf Exp $
#

DISTNAME=	quanta-2.0-pr1
PKGNAME=	quanta-2.0pr1
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quanta/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://quanta.sourceforge.net/
COMMENT= 	HTML editor suitable for experienced web developers

DEPENDS+=	kdebase>=2.1:../../x11/kdebase2

USE_INTL=	yes
BUILD_USES_MSGFMT=	yes
WRKSRC=		${WRKDIR}/quanta

.include "../../x11/kde2/Makefile.part2"

.include "../../mk/bsd.pkg.mk"
