# $NetBSD: Makefile,v 1.3 2009/06/14 20:19:24 sno Exp $

DISTNAME=	DateTime-Format-Flexible-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?DateTime::Format::Flexible
COMMENT=	Flexibly parse strings and turn them into DateTime objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.74:../../time/p5-DateTime-Format-Builder
DEPENDS+=	p5-DateTime-TimeZone-[0-9]*:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Readonly>=0.06:../../devel/p5-Readonly

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=	#

PERL5_PACKLIST=	auto/DateTime/Format/Flexible/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
