# $NetBSD: Makefile,v 1.9 2002/09/20 17:00:41 abs Exp $
#

COMMENT=	Open new communicator, navigator, or mozilla window

BINNAME=	netscape

.include "../navigator/Makefile.common"

.if defined(NS_PREFERRED) && ${NS_PREFERRED} == mozilla
NETSCAPE_PREFERRED=mozilla:navigator:communicator:netscape7
.elif defined(NS_PREFERRED) && ${NS_PREFERRED} == netscape7
NETSCAPE_PREFERRED=netscape7:navigator:communicator:mozilla
.elif defined(NS_PREFERRED) && ${NS_PREFERRED} == navigator
NETSCAPE_PREFERRED=navigator:communicator:mozilla:netscape7
.else
NETSCAPE_PREFERRED=communicator:navigator:mozilla:netscape7
.endif

DEPENDS+= ns-remote>=1.3:../../www/ns-remote
DEPENDS+={${NETSCAPE_PREFERRED:C:\::,:g}}-[0-9]*:../../www/${NETSCAPE_PREFERRED:S:\:.*::}

DISTFILES=	# empty
MASTER_SITES=	# empty

USE_BUILDLINK2=	# defined

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

do-build:
	${SED} "s/@NETSCAPE_PREFERRED@/${NETSCAPE_PREFERRED}/" \
				${FILESDIR}/netscape > ${WRKSRC}/netscape

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${PREFIX}/bin/netscape

.include "../../emulators/suse_linux/Makefile.application"
