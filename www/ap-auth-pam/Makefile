# $NetBSD: Makefile,v 1.6 2004/04/24 22:46:12 jlam Exp $

DISTNAME=	mod_auth_pam-1.0a
PKGNAME=	ap-auth-pam-1.0a
CATEGORIES=	www
MASTER_SITES=	http://pam.sourceforge.net/mod_auth_pam/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pam.sourceforge.net/mod_auth_pam/
COMMENT=	Module to allow Apache authentication using PAM

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_auth_pam.so
LDFLAGS+=		-lpam

EGDIR=		${PREFIX}/share/examples/mod_auth_pam
HTMLDIR=	${PREFIX}/share/doc/html/mod_auth_pam

post-install:
	${INSTALL_DATA_DIR} ${EGDIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/httpd ${EGDIR}/httpd.pam
	${INSTALL_DATA} ${WRKSRC}/doc/configure.html ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/faq.html ${HTMLDIR}

.include "../../security/PAM/buildlink2.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
