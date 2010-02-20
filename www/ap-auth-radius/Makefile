# $NetBSD: Makefile,v 1.7 2010/02/20 14:58:44 joerg Exp $
#

DISTNAME=	mod_auth_radius-1.5.7
PKGNAME=	ap13-auth-radius-1.5.7
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freeradius.org/mod_auth_radius/
COMMENT=	Radius authentication module for Apache

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ap-auth-radius-[0-9]*

APACHE_MODULE_NAME=	mod_auth_radius.so

EXAMPLEDIR=		${PREFIX}/share/example/mod_auth_radius
post-extract:
		${RM} -f ${WRKSRC}/mod_auth_radius-2.0.c

INSTALLATION_DIRS+=	${EXAMPLEDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${EXAMPLEDIR}/
	${INSTALL_DATA} ${WRKSRC}/httpd.conf ${DESTDIR}${EXAMPLEDIR}/
	${INSTALL_DATA} ${WRKSRC}/htaccess ${DESTDIR}${EXAMPLEDIR}/

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
