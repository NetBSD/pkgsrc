# $NetBSD: Makefile,v 1.6 2003/08/09 11:29:16 seb Exp $
#

DISTNAME=		gcal-3.01
PKGREVISION=		1
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=gcal/}

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gcal/gcal.html
COMMENT=		Gnu version of the standard calendar utility

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

INFO_FILES=		gcal.info
GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
