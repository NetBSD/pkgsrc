# $NetBSD: Makefile,v 1.1.1.1 2003/06/14 23:21:46 atatat Exp $
#

DISTNAME=		gcal-3.01
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=gcal/}

MAINTAINER=		atatat@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcal/gcal.html
COMMENT=		Gnu version of the standard calendar utility

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
