# $NetBSD: Makefile,v 1.7 2014/06/11 12:57:23 joerg Exp $
#

DISTNAME=	ntlm2
PKGNAME=	${APACHE_PKG_PREFIX}-auth-ntlm-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://www.jamiekerwick.co.uk/modntlm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://modntlm.sourceforge.net/
COMMENT=	Apache module for NTLM authentication

PKG_APACHE_ACCEPTED=	apache22

APACHE_MODULE_NAME=	mod_ntlm.${MODULE_EXT}

WRKSRC=		${WRKDIR}

DISTVERS=	0.2
MODULE_EXT=	la

MESSAGE_SUBST+=	MODULE_NAME=ntlm_module
MESSAGE_SUBST+=	EGDIR=${EGDIR}

EGDIR=		${PREFIX}/share/examples/mod_ntlm

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/ntlm.conf ${DESTDIR}${EGDIR}

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
