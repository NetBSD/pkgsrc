# $NetBSD: Makefile,v 1.17 2004/03/09 18:52:15 kristerw Exp $
#

DISTNAME=	netscape-20040123
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@NetBSD.org
COMMENT=	Open new window using netscape-like browser

DEPENDS+= ns-remote>=1.3:../../www/ns-remote
DEPENDS+={${NETSCAPE_PREFERRED:C/:/,/g}}-[0-9]*:../../www/${NETSCAPE_PREFERRED:C/:.*//}

NETSCAPE_PREFERRED_DEFAULT=firefox:mozilla:firefox-bin:netscape7:communicator:navigator
.if defined(NS_PREFERRED)
NETSCAPE_PREFERRED=${NS_PREFERRED}:${NETSCAPE_PREFERRED_DEFAULT}
.else
NETSCAPE_PREFERRED=${NETSCAPE_PREFERRED_DEFAULT}
.endif

USE_BUILDLINK2=	# defined

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

do-build:
	${SED} "s/@NETSCAPE_PREFERRED@/${NETSCAPE_PREFERRED}/" \
				${FILESDIR}/netscape > ${WRKSRC}/netscape

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${PREFIX}/bin/netscape

.include "../../mk/bsd.pkg.mk"
