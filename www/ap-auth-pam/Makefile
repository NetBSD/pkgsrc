# $NetBSD: Makefile,v 1.1.1.1 2002/03/06 19:33:38 jlam Exp $

DISTNAME=	mod_auth_pam-1.0a
PKGNAME=	ap-auth-pam-1.0a
CATEGORIES=	www
MASTER_SITES=	http://pam.sourceforge.net/mod_auth_pam/dist/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://pam.sourceforge.net/mod_auth_pam/
COMMENT=	module to allow Apache authentication using PAM

DEPENDS+=	${BUILDLINK_DEPENDS.apache}:../../www/apache

USE_BUILDLINK_ONLY=	YES

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

.include "../../security/PAM/buildlink.mk"
.include "../../www/apache/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
