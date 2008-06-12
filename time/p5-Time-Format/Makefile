# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:52 joerg Exp $
#

DISTNAME=	Time-Format-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RO/ROODE/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RO/ROODE/
COMMENT=	Easy-to-use date/time formatting

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Test-Simple>=0.40:../../devel/p5-Test-Simple

PERL5_PACKLIST=	auto/Time/Format/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
