# $NetBSD: Makefile,v 1.1.1.1 2002/04/01 17:44:43 tv Exp $
#

DISTNAME=	mod_gzip.c
PKGNAME=	ap-gzip-${VERSION}
CATEGORIES=	www
MASTER_SITES=	http://www.remotecommunications.com/apache/mod_gzip/src/${VERSION}/
EXTRACT_SUFX=	.gz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} changes.txt commands.txt samples.txt

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.remotecommunications.com/apache/mod_gzip/
COMMENT=	On-the-fly GZIP compression for Apache 1.3.x

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
# For "apxs":
BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

VERSION=	1.3.19.1a
DIST_SUBDIR=	${PKGNAME}

EXTRACT_CMD=	${GZIP_CMD} -dc >${WRKDIR}/${DISTNAME} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c -o mod_gzip.so *.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_gzip.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_gzip
	${INSTALL_DATA} ${_DISTDIR}/*.txt ${PREFIX}/share/doc/mod_gzip/

.include "../../mk/bsd.pkg.mk"
