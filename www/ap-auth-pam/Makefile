# $NetBSD: Makefile,v 1.2 2002/08/25 21:51:45 jlam Exp $

DISTNAME=	mod_auth_pam-1.0a
PKGNAME=	ap-auth-pam-1.0a
CATEGORIES=	www
MASTER_SITES=	http://pam.sourceforge.net/mod_auth_pam/dist/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://pam.sourceforge.net/mod_auth_pam/
COMMENT=	module to allow Apache authentication using PAM

USE_BUILDLINK2=	YES
APACHE_MODULE=	YES

LIBS+=		-lpam
EGDIR=		${PREFIX}/share/examples/mod_auth_pam
HTMLDIR=	${PREFIX}/share/doc/html/mod_auth_pam

do-build:
	cd ${WRKSRC}; ${APXS} -c $(CPPFLAGS) $(LDFLAGS) $(LIBS) mod_auth_pam.c

do-install:
	@cd ${WRKSRC}; ${APXS} -i mod_auth_pam.so
	${INSTALL_DATA_DIR} ${EGDIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/httpd ${EGDIR}/httpd.pam
	${INSTALL_DATA} ${WRKSRC}/doc/configure.html ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/faq.html ${HTMLDIR}

.include "../../security/PAM/buildlink2.mk"
.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
