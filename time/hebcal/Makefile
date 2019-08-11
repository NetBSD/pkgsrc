# $NetBSD: Makefile,v 1.12 2019/08/11 13:24:03 wiz Exp $
#

DISTNAME=	hebcal-3.11
PKGREVISION=	5
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hebcal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hebcal.sourceforge.net/
COMMENT=	Perpetual Hebrew calendar
LICENSE=	gnu-gpl-v2

INFO_FILES=	yes

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_TOOLS+=	perl
USE_TOOLS+=	m4
USE_TOOLS+=	makeinfo

# Remove an empty hebcal.info file to force it to be generated
# properly during the build.
#
post-extract:
	${RUN}${RM} -f ${WRKSRC}/doc/*.info

.include "../../mk/bsd.pkg.mk"
