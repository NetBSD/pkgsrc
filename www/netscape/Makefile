# $NetBSD: Makefile,v 1.3 2001/04/12 15:35:40 abs Exp $
#

COMMENT=	Open new communicator or navigator window

BINNAME=	netscape

.include "../navigator/Makefile.common"

DEPENDS+= ns-remote>=1.3:../../www/ns-remote
.if defined(NS_NAVIGATOR) && ${NS_NAVIGATOR} == YES
DEPENDS+= {navigator,communicator}-*:../../www/navigator
.else
DEPENDS+= {communicator,navigator}-*:../../www/communicator
.endif

DISTFILES=	# empty
MASTER_SITES=	# empty

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

do-install:
.if defined(NS_NAVIGATOR) && ${NS_NAVIGATOR} == YES
	${INSTALL_SCRIPT} ${FILESDIR}/netscape_navigator ${PREFIX}/bin/netscape
.else
	${LN} -sf ns-open ${PREFIX}/bin/netscape
.endif

.include "../../mk/bsd.pkg.mk"
