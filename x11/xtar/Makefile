# $NetBSD: Makefile,v 1.1 2022/01/07 12:43:14 nia Exp $

DISTNAME=	xtar-1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ftp.gwdg.de/pub/x11/x.org/contrib/utilities/
COMMENT=	View and manipulate the contents of a tar file
LICENSE=	modified-bsd # ish

USE_IMAKE=	yes

MAKE_JOBS_SAFE=	no

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
