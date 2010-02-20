# $NetBSD: Makefile,v 1.15 2010/02/20 14:58:44 joerg Exp $

DISTNAME=	mod_auth_pam-1.0a
PKGNAME=	ap13-auth-pam-1.0a
CATEGORIES=	www
MASTER_SITES=	http://pam.sourceforge.net/mod_auth_pam/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pam.sourceforge.net/mod_auth_pam/
COMMENT=	Module to allow Apache authentication using PAM

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ap-auth-pam-[0-9]*

APACHE_MODULE_NAME=	mod_auth_pam.so
LDFLAGS+=		-lpam

EGDIR=		${PREFIX}/share/examples/mod_auth_pam
HTMLDIR=	${PREFIX}/share/doc/html/mod_auth_pam

INSTALLATION_DIRS+=	${EGDIR} ${HTMLDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/samples/httpd ${DESTDIR}${EGDIR}/httpd.pam
	${INSTALL_DATA} ${WRKSRC}/doc/configure.html ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/faq.html ${DESTDIR}${HTMLDIR}

.include "../../www/apache/module.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
