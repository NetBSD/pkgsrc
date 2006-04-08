# $NetBSD: Makefile,v 1.13 2006/04/08 05:02:59 jlam Exp $
#

DISTNAME=		gcal-3.01
PKGREVISION=		4
CATEGORIES=		time
MASTER_SITES=		${MASTER_SITE_GNU:=gcal/}

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/gcal/gcal.html
COMMENT=		Gnu version of the standard calendar utility

USE_PKGLOCALEDIR=	yes

INFO_FILES=		# PLIST
GNU_CONFIGURE=		yes
BUILD_USES_MSGFMT=	yes
BROKEN_GETTEXT_DETECTION=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
