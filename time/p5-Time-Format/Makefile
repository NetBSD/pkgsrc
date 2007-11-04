# $NetBSD: Makefile,v 1.1.1.1 2007/11/04 15:08:44 adrianp Exp $
#

DISTNAME=	Time-Format-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RO/ROODE/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RO/ROODE/
COMMENT=	Easy-to-use date/time formatting

DEPENDS+=	p5-Test-Simple>=0.40:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Time/Format/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
