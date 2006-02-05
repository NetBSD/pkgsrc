# $NetBSD: Makefile,v 1.4 2006/02/05 23:11:17 joerg Exp $
#

DISTNAME=	mod_auth_radius-1.5.7
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/
EXTRACT_SUFX=	.tar

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://www.freeradius.org/mod_auth_radius/
COMMENT=	Radius authentication module for Apache


APACHE_MODULE_NAME=	mod_auth_radius.so

EXAMPLEDIR=		${PREFIX}/share/example/mod_auth_radius
post-extract:
		${RM} -f ${WRKSRC}/mod_auth_radius-2.0.c

post-install:
		 ${INSTALL_DATA_DIR} ${EXAMPLEDIR}
		 ${INSTALL_DATA} ${WRKSRC}/README ${EXAMPLEDIR}/
		 ${INSTALL_DATA} ${WRKSRC}/httpd.conf ${EXAMPLEDIR}/
		 ${INSTALL_DATA} ${WRKSRC}/htaccess ${EXAMPLEDIR}/

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
