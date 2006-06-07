# $NetBSD: Makefile,v 1.15 2006/06/07 02:17:32 grant Exp $
#

DISTNAME=		gcal-3.01
PKGREVISION=		4
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=gcal/}

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gcal/gcal.html
COMMENT=		GNU version of the standard calendar utility

USE_PKGLOCALEDIR=	yes

INFO_FILES=		# PLIST
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt
BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
