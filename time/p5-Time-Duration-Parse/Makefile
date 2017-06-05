# $NetBSD: Makefile,v 1.14 2017/06/05 14:25:06 ryoon Exp $

DISTNAME=	Time-Duration-Parse-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Duration-Parse/
COMMENT=	Perl5 module to parse string that represents time duration
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Time/Duration/Parse/.packlist

BUILD_DEPENDS+=	p5-Time-Duration-[0-9]*:../../time/p5-Time-Duration
DEPENDS+=	p5-Exporter-Lite-[0-9]*:../../devel/p5-Exporter-Lite

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
