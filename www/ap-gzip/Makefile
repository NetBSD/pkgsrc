# $NetBSD: Makefile,v 1.4 2002/10/22 12:46:42 wiz Exp $
#

DISTNAME=	mod_gzip-${VERSION}
PKGNAME=	ap-gzip-${VERSION}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mod-gzip/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.sourceforge.net/projects/mod-gzip/
COMMENT=	On-the-fly GZIP compression for Apache 1.3.x

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
USE_PERL5=	build	# for "apxs"

VERSION=	1.3.26.1a

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c -o mod_gzip.so *.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_gzip.so
	${INSTALL_DATA_DIR} \
		${PREFIX}/share/doc/mod_gzip \
		${PREFIX}/share/doc/mod_gzip/de \
		${PREFIX}/share/doc/mod_gzip/en \
		${PREFIX}/share/examples/mod_gzip
	${INSTALL_DATA} ${WRKSRC}/docs/manual/deutsch/* \
		${PREFIX}/share/doc/mod_gzip/de/
	${INSTALL_DATA} ${WRKSRC}/docs/manual/english/* \
		${PREFIX}/share/doc/mod_gzip/en/
	${INSTALL_DATA} ${WRKSRC}/docs/mod_gzip.conf.sample \
		${PREFIX}/share/examples/mod_gzip/httpd.conf

.include "../../mk/bsd.pkg.mk"
