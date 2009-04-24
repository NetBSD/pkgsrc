# $NetBSD: Makefile,v 1.2 2009/04/24 17:15:23 sno Exp $

DISTNAME=	DateTimeX-Easy-0.085
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTimeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?DateTimeX::Easy
COMMENT=	Parse a date/time string using the best method available

DEPENDS+=	p5-DateTime-Format-DateParse>0:../../time/p5-DateTime-Format-DateParse
DEPENDS+=	p5-DateTime-Format-Natural>0:../../time/p5-DateTime-Format-Natural
DEPENDS+=	p5-DateTime-Format-Flexible>0:../../time/p5-DateTime-Format-Flexible
DEPENDS+=	p5-DateTime-Format-ICal>0:../../time/p5-DateTime-Format-ICal
DEPENDS+=	p5-DateTime-Format-DateManip>0:../../time/p5-DateTime-Format-DateManip
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils

BUILD_DEPENDS+=	p5-Test-Most>0:../../devel/p5-Test-Most

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=	#

PERL5_PACKLIST=	auto/DateTimeX/Easy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
