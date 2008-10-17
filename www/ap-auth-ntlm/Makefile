# $NetBSD: Makefile,v 1.1.1.1 2008/10/17 19:23:25 sborrill Exp $
#

DISTNAME=	ntlm1
PKGNAME=	${APACHE_PKG_PREFIX}-auth-ntlm-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://www.jamiekerwick.co.uk/modntlm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://modntlm.sourceforge.com/
COMMENT=	Apache module for NTLM authentication

PKG_APACHE_ACCEPTED=	apache13

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_ntlm.${MODULE_EXT}

WRKSRC=		${WRKDIR}

DISTVERS=	0.5
MODULE_EXT=	so
MESSAGE_SUBST+=	MODULE_NAME=ntlm_module
MESSAGE_SUBST+=	EGDIR=${EGDIR}

EGDIR=		${PREFIX}/share/examples/mod_ntlm

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ntlm.conf ${EGDIR}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
