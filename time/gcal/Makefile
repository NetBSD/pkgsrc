# $NetBSD: Makefile,v 1.7 2004/04/11 09:23:06 snj Exp $
#

DISTNAME=		gcal-3.01
PKGREVISION=		1
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
