# $NetBSD: Makefile,v 1.14 2003/03/31 16:26:20 bouyer Exp $
#

DISTNAME=	textutils-2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=textutils/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/textutils/textutils.html
COMMENT=	GNU text utilities

USE_PERL5=		build
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS=	--program-prefix=${GNU_PROGRAM_PREFIX}
.endif
PLIST_SUBST+=	GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=	GNU_PROGRAM_PREFIX

post-install:
	${INSTALL_INFO} ${PREFIX}/info/textutils.info ${PREFIX}/info/dir

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
