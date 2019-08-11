# $NetBSD: Makefile,v 1.11 2019/08/11 13:24:13 wiz Exp $
#

DISTNAME=	rem2ics-0.93
PKGREVISION=	9
CATEGORIES=	time
MASTER_SITES=	http://mark.atwood.name/code/rem2ics/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/rem2ics/
COMMENT=	Convert remind output into RFC2445 iCalendar format
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run pod2man

MAKE_FILE=	rem2ics-Makefile
BUILD_TARGET=	rem2ics.1
REPLACE_PERL=	rem2ics

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rem2ics ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/rem2ics.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
