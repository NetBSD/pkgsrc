# $NetBSD: Makefile,v 1.8 2023/11/03 21:27:40 wiz Exp $

UCD_VERSION=	15.1.0
DISTNAME=	unicode-character-database-${UCD_VERSION}
CATEGORIES=	textproc
MASTER_SITES=	http://www.unicode.org/Public/zipped/${UCD_VERSION}/
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	UCD.zip
DISTFILES+=	Unihan.zip

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://www.unicode.org/ucd/
COMMENT=	Unicode Character Database
LICENSE=	unicode

USE_LANGUAGES=	# none
USE_TOOLS+=	pax
NO_BUILD=	YES
NO_CONFIGURE=	YES

EXTRACT_DIR=	${WRKDIR}/${DISTNAME}
UCDDIR=		${PREFIX}/share/unicode/ucd

INSTALLATION_DIRS=	${UCDDIR}

do-install:
	cd ${EXTRACT_DIR} && pax -rwpp -s '/.*\.orig//' . ${DESTDIR}${UCDDIR}
	for _f in ${DISTFILES}; do				\
		${INSTALL_DATA} ${_DISTDIR}/$${_f} ${DESTDIR}${UCDDIR};	\
	done
	${FIND} ${DESTDIR}${UCDDIR} \
		-type f -exec ${CHMOD} ${SHAREMODE} {} \;

.include "../../mk/bsd.pkg.mk"
