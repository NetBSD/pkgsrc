# $NetBSD: Makefile,v 1.7 2002/04/05 11:56:28 tron Exp $
#

COMMENT=	Open new communicator, navigator, or mozilla window

BINNAME=	netscape

.include "../navigator/Makefile.common"

DEPENDS+= ns-remote>=1.3:../../www/ns-remote
.if defined(NS_PREFERRED) && ${NS_PREFERRED} == mozilla
DEPENDS+= {mozilla,navigator,communicator}-[0-9]*:../../www/mozilla
.else
.if defined(NS_PREFERRED) && ${NS_PREFERRED} == navigator
DEPENDS+= {navigator,communicator,mozilla}-[0-9]*:../../www/navigator
.else
DEPENDS+= {communicator,navigator,mozilla}-[0-9]*:../../www/communicator
.endif
.endif

DISTFILES=	# empty
MASTER_SITES=	# empty

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

do-install:

.if defined(NS_PREFERRED) && ${NS_PREFERRED} == mozilla
	${INSTALL_SCRIPT} ${FILESDIR}/netscape_mozilla ${PREFIX}/bin/netscape
.else
.if defined(NS_PREFERRED) && ${NS_PREFERRED} == navigator
	${INSTALL_SCRIPT} ${FILESDIR}/netscape_navigator ${PREFIX}/bin/netscape
.else
	${LN} -sf ns-open ${PREFIX}/bin/netscape
.endif
.endif

.include "../../emulators/suse_linux/Makefile.application"
