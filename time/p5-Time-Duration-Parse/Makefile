# $NetBSD: Makefile,v 1.18 2019/06/30 20:17:17 nia Exp $

DISTNAME=	Time-Duration-Parse-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Time-Duration-Parse
COMMENT=	Perl5 module to parse string that represents time duration
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Time/Duration/Parse/.packlist

BUILD_DEPENDS+=	p5-Time-Duration-[0-9]*:../../time/p5-Time-Duration
DEPENDS+=	p5-Exporter-Lite-[0-9]*:../../devel/p5-Exporter-Lite

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
