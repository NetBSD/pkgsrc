# $NetBSD: Makefile,v 1.6 2011/08/14 15:28:49 obache Exp $
#

DISTNAME=	Time-Interval-1.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	time
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AH/AHICOX/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AH/AHICOX/
COMMENT=	Converts time intervals of days, hours, minutes, and seconds

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime

PERL5_PACKLIST=	auto/Time/Interval/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
