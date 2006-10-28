# $NetBSD: Makefile,v 1.16 2006/10/28 21:29:47 wiz Exp $
#

DISTNAME=	mod_gzip-1.3.26.1a
PKGNAME=	${DISTNAME:C|mod_|ap13-|}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mod-gzip/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mod-gzip/
COMMENT=	On-the-fly GZIP compression for Apache 1.3.x

CONFLICTS=	ap-gzip-[0-9]*

APACHE_MODULE_NAME=	mod_gzip.so

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_gzip
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_gzip/de
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_gzip/en
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mod_gzip
	${INSTALL_DATA} ${WRKSRC}/docs/manual/deutsch/* \
		${PREFIX}/share/doc/mod_gzip/de
	${INSTALL_DATA} ${WRKSRC}/docs/manual/english/* \
		${PREFIX}/share/doc/mod_gzip/en
	${INSTALL_DATA} ${WRKSRC}/docs/mod_gzip.conf.sample \
		${PREFIX}/share/examples/mod_gzip/httpd.conf

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
