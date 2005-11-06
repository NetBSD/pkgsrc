# $NetBSD: Makefile,v 1.6 2005/11/06 22:11:26 kristerw Exp $
#

COMMENT=	Streaming multimedia plugin for Netscape (communicator)

BINNAME=	communicator
COMMONDIR=	../../www/ns-plugger-common

DEPENDS+=	ns-plugger-common-[0-9]*:${COMMONDIR}

PLIST_SRC=	${.CURDIR}/PLIST
PKGDIR=		${.CURDIR}/${COMMONDIR}

.include "${COMMONDIR}/Makefile"
