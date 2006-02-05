# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:26 joerg Exp $
#

PKGREVISION=	1
COMMENT=	Streaming multimedia plugin for Netscape (communicator)

BINNAME=	communicator
COMMONDIR=	../../www/ns-plugger-common

DEPENDS+=	ns-plugger-common-[0-9]*:${COMMONDIR}

PLIST_SRC=	${.CURDIR}/PLIST
PKGDIR=		${.CURDIR}/${COMMONDIR}

.include "${COMMONDIR}/Makefile"
