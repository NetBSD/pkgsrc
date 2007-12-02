# $NetBSD: Makefile,v 1.18 2007/12/02 12:34:01 wiz Exp $
#

DISTNAME=	weblint-1.020
CATEGORIES=	www
MASTER_SITES=	http://www.perl.com/CPAN/authors/id/NEILB/ \
		ftp://ftp.gmd.de/mirrors/CPAN/authors/id/NEILB/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.weblint.org/
COMMENT=	HTML validator and sanity checker

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		perl:run
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
