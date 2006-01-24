# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:41 wiz Exp $

DISTNAME=	mod_auth_pam-1.0a
PKGNAME=	ap-auth-pam-1.0a
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pam.sourceforge.net/mod_auth_pam/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pam.sourceforge.net/mod_auth_pam/
COMMENT=	Module to allow Apache authentication using PAM


APACHE_MODULE_NAME=	mod_auth_pam.so
LDFLAGS+=		-lpam

EGDIR=		${PREFIX}/share/examples/mod_auth_pam
HTMLDIR=	${PREFIX}/share/doc/html/mod_auth_pam

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/httpd ${EGDIR}/httpd.pam
	${INSTALL_DATA} ${WRKSRC}/doc/configure.html ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/faq.html ${HTMLDIR}

.include "../../www/apache/module.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
