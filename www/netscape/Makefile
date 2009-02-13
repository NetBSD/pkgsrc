# $NetBSD: Makefile,v 1.24 2009/02/13 22:32:48 abs Exp $
#

DISTNAME=	netscape-20040123
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	abs@NetBSD.org
COMMENT=	Open new window using netscape-like browser

.include "../../mk/bsd.prefs.mk"

DEPENDS+= ns-remote>=1.3:../../www/ns-remote
DEPENDS+={${NETSCAPE_PREFERRED:C/:/,/g}}-[0-9]*:../../www/${NETSCAPE_PREFERRED:C/:.*//}

NETSCAPE_PREFERRED_DEFAULT=firefox:mozilla:firefox-bin:netscape7:communicator:navigator
.if defined(NS_PREFERRED)
NETSCAPE_PREFERRED=${NS_PREFERRED}:${NETSCAPE_PREFERRED_DEFAULT}
.else
NETSCAPE_PREFERRED=${NETSCAPE_PREFERRED_DEFAULT}
.endif

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

INSTALLATION_DIRS=	bin
PKG_DESTDIR_SUPPORT=	user-destdir

do-build:
	${SED} "s/@NETSCAPE_PREFERRED@/${NETSCAPE_PREFERRED}/" \
				${FILESDIR}/netscape > ${WRKSRC}/netscape

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${DESTDIR}${PREFIX}/bin/netscape

.include "../../mk/bsd.pkg.mk"
