# $NetBSD: Makefile,v 1.15 2005/07/16 19:10:41 jlam Exp $
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
INSTALLATION_DIRS+=	bin man/man1

.include "../../mk/bsd.pkg.mk"
