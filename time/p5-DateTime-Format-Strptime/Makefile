# $NetBSD: Makefile,v 1.6 2009/07/18 22:00:08 sno Exp $

DISTNAME=	DateTime-Format-Strptime-1.1000
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rickm/DateTime-Format-Strptime/
COMMENT=	Parse and format strp and strf time patterns
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DateTime>=0.4304:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Locale>=0.43:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=0.79:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Params-Validate>=0.64:../../devel/p5-Params-Validate

PERL5_PACKLIST=		auto/DateTime/Format/Strptime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
