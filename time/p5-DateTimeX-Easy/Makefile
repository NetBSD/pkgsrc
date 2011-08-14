# $NetBSD: Makefile,v 1.8 2011/08/14 15:28:47 obache Exp $

DISTNAME=	DateTimeX-Easy-0.089
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTimeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?DateTimeX::Easy
COMMENT=	Parse a date/time string using the best method available
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Flexible-[0-9]*:../../time/p5-DateTime-Format-Flexible
DEPENDS+=	p5-DateTime-Format-ICal-[0-9]*:../../time/p5-DateTime-Format-ICal
DEPENDS+=	p5-DateTime-Format-Natural-[0-9]*:../../time/p5-DateTime-Format-Natural
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

BUILD_DEPENDS+=	p5-Test-Most>0:../../devel/p5-Test-Most

PERL5_MODULE_TYPE=	Module::Install::Bundled
PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=	#

PERL5_PACKLIST=	auto/DateTimeX/Easy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
