# $NetBSD: Makefile,v 1.13 2004/02/17 02:11:30 minskim Exp $
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

USE_BUILDLINK3=	YES

INSTALLATION_DIRS+=	bin man/man1

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
