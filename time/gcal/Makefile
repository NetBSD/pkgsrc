# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:21 tv Exp $
#

DISTNAME=		gcal-3.01
PKGREVISION=		3
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=gcal/}

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gcal/gcal.html
COMMENT=		Gnu version of the standard calendar utility

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes

INFO_FILES=		gcal.info
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
