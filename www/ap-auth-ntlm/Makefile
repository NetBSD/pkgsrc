# $NetBSD: Makefile,v 1.3 2012/10/28 06:30:03 asau Exp $
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

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/ntlm.conf ${DESTDIR}${EGDIR}

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
