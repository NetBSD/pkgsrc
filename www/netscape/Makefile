# $NetBSD: Makefile,v 1.4 2001/07/27 14:26:18 abs Exp $
#

COMMENT=	Open new communicator, navigator, or mozilla window

BINNAME=	netscape

.include "../navigator/Makefile.common"

DEPENDS+= ns-remote>=1.3:../../www/ns-remote
.if defined(NS_PREFERRED) && ${NS_PREFERRED} == mozilla
DEPENDS+= {mozilla,navigator,communicator}-*:../../www/mozilla
.else
.if defined(NS_PREFERRED) && ${NS_PREFERRED} == navigator
DEPENDS+= {navigator,communicator,mozilla}-*:../../www/navigator
.else
DEPENDS+= {communicator,navigator,mozilla}-*:../../www/communicator
.endif
.endif

DISTFILES=	# empty
MASTER_SITES=	# empty

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
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

.include "../../mk/bsd.pkg.mk"
