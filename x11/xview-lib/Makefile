# $NetBSD: Makefile,v 1.12 2000/12/29 15:07:21 dmcmahill Exp $
# $FreeBSD Id: Makefile,v 1.13 1997/07/17 15:13:03 max Exp
#

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-lib-3.2.1nb2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jlam@netbsd.org

DEPENDS=		xview-config>=3.2.1nb2:../../x11/xview-config

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
NOT_FOR_PLATFORM=       *-*-alpha       # broken va_arg handling.

USE_IMAKE=		# defined

.include "../../mk/bsd.pkg.mk"
