# $NetBSD: Makefile,v 1.5 2003/02/17 17:52:02 grant Exp $
#

DISTNAME=	mod_gzip-1.3.26.1a
PKGNAME=	${DISTNAME:C|mod_|ap-|}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mod-gzip/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.sourceforge.net/projects/mod-gzip/
COMMENT=	On-the-fly GZIP compression for Apache 1.3.x

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_gzip.so
APACHE_MODULE_SRC=	*.c

post-install:
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

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
