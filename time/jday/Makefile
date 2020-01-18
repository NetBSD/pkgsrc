# $NetBSD: Makefile,v 1.10 2020/01/18 23:35:37 rillig Exp $

DISTNAME=		jday-2.4
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jday/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://jday.sourceforge.net/
COMMENT=		Julian date calculator
LICENSE=		2-clause-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	jday.pc.in

do-test:
	(cd ${WRKSRC} && ./RunTest)
	(cd ${WRKSRC} && ./Testdbd)

INSTALLATION_DIRS=	share/jday

post-install:
	${INSTALL_DATA} ${WRKSRC}/CalDate.inc ${DESTDIR}${PREFIX}/share/jday
	${INSTALL_DATA} ${WRKSRC}/CalDate.pm ${DESTDIR}${PREFIX}/share/jday
	${INSTALL_DATA} ${WRKSRC}/J2D.pl ${DESTDIR}${PREFIX}/share/jday
	${INSTALL_DATA} ${WRKSRC}/Jday.php ${DESTDIR}${PREFIX}/share/jday
	${INSTALL_DATA} ${WRKSRC}/Jday.pl ${DESTDIR}${PREFIX}/share/jday
	${INSTALL_DATA} ${WRKSRC}/dbd.awk ${DESTDIR}${PREFIX}/share/jday
	${INSTALL_DATA} ${WRKSRC}/jday.awk ${DESTDIR}${PREFIX}/share/jday

.include "../../mk/bsd.pkg.mk"
