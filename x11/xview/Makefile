# $NetBSD: Makefile,v 1.9 2000/12/29 15:07:21 dmcmahill Exp $
#

DISTNAME=	xview3.2p1-X11R6
PKGNAME=	xview-3.2.1
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@netbsd.org

DEPENDS+=	xview-config>=3.2.1:../xview-config
DEPENDS+=	xview-lib>=3.2.1:../xview-lib
DEPENDS+=	xview-clients>=3.2.1:../xview-clients

NOT_FOR_PLATFORM=       *-*-alpha       # broken va_arg handling in xview-lib

USE_X11=	# defined

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
NO_PATCH=	# defined
NO_BUILD=	# defined
NO_CONFIGURE=	# defined

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
