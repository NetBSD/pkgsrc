# $NetBSD: Makefile,v 1.17 2010/02/20 14:58:45 joerg Exp $
#

DISTNAME=	mod_gzip-1.3.26.1a
PKGNAME=	${DISTNAME:C|mod_|ap13-|}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mod-gzip/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mod-gzip/
COMMENT=	On-the-fly GZIP compression for Apache 1.3.x

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ap-gzip-[0-9]*

APACHE_MODULE_NAME=	mod_gzip.so

INSTALLATION_DIRS+=	share/doc/mod_gzip/de share/doc/mod_gzip/en \
			share/examples/mod_gzip

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/manual/deutsch/* \
	    ${DESTDIR}${PREFIX}/share/doc/mod_gzip/de
	${INSTALL_DATA} ${WRKSRC}/docs/manual/english/* \
	    ${DESTDIR}${PREFIX}/share/doc/mod_gzip/en
	${INSTALL_DATA} ${WRKSRC}/docs/mod_gzip.conf.sample \
	    ${DESTDIR}${PREFIX}/share/examples/mod_gzip/httpd.conf

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
