# $NetBSD: Makefile,v 1.10 2000/10/16 06:39:28 jlam Exp $
# $FreeBSD Id: Makefile,v 1.13 1997/07/17 15:13:03 max Exp
#

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-lib-3.2.1nb1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jlam@netbsd.org

DEPENDS=		xview-config>=3.2.1nb1:../../x11/xview-config

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

USE_IMAKE=		# defined
XMKMF=			${X11PREFIX}/bin/xvmkmf -a

.include "../../mk/bsd.pkg.mk"
