# $NetBSD: Makefile,v 1.2 2010/02/12 21:17:22 joerg Exp $
#

DISTNAME=	ntlm2
PKGNAME=	${APACHE_PKG_PREFIX}-auth-ntlm-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://www.jamiekerwick.co.uk/modntlm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://modntlm.sourceforge.com/
COMMENT=	Apache module for NTLM authentication

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_ntlm.${MODULE_EXT}

WRKSRC=		${WRKDIR}

DISTVERS=	0.2
MODULE_EXT=	la

MESSAGE_SUBST+=	MODULE_NAME=ntlm_module
MESSAGE_SUBST+=	EGDIR=${EGDIR}

EGDIR=		${PREFIX}/share/examples/mod_ntlm

INSTALLATION_DIRS+=	lib/httpd ${EGDIR}

do-install:
	${INSTALL_LIB} ${WRKSRC}/.libs/mod_ntlm.so ${DESTDIR}${PREFIX}/lib/httpd
	${INSTALL_DATA} ${WRKSRC}/ntlm.conf ${DESTDIR}${EGDIR}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
