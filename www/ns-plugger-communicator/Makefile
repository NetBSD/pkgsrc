# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:53 jlam Exp $
#

COMMENT=	streaming multimedia plugin for Netscape (communicator)

BINNAME=	communicator
COMMONDIR=	../ns-plugger-common

DEPENDS+=	ns-plugger-common-[0-9]*:${COMMONDIR}

PLIST_SRC=	${.CURDIR}/pkg/PLIST
PKGDIR=		${.CURDIR}/${COMMONDIR}/pkg

.include "${COMMONDIR}/Makefile"
