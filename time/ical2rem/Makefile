# $NetBSD: Makefile,v 1.9 2018/08/22 09:47:14 wiz Exp $

DISTNAME=	ical2rem.pl
PKGNAME=	ical2rem-0.5.2
PKGREVISION=	6
CATEGORIES=	time
#MASTER_SITES=	http://jalcorn.net/
EXTRACT_SUFX=	.txt

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://jalcorn.net/
COMMENT=	Convert iCal files to remind format
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-iCal-Parser-[0-9]*:../../textproc/p5-iCal-Parser

INSTALLATION_DIRS=	bin

EXTRACT_ONLY=	# empty

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

USE_TOOLS+=	perl:run
REPLACE_PERL=	ical2rem

do-extract:
	cp ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${WRKSRC}/ical2rem

do-build:
	# nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ical2rem ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
