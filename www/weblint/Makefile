# $NetBSD: Makefile,v 1.16 2005/12/27 22:19:12 reed Exp $
#

DISTNAME=	weblint-1.020
CATEGORIES=	www
MASTER_SITES=	http://www.perl.com/CPAN/authors/id/NEILB/ \
		ftp://ftp.loaded.net/pub/CPAN/authors/id/NEILB/ \
		ftp://ftp.freesoftware.com/pub/perl/CPAN/authors/id/NEILB/ \
		ftp://ftp.gmd.de/mirrors/CPAN/authors/id/NEILB/ \
		ftp://cpan.perl.org/CPAN/authors/id/NEILB/

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	http://www.weblint.org/
COMMENT=	HTML validator and sanity checker

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		perl:run
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
