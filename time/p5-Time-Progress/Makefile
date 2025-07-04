# $NetBSD: Makefile,v 1.27 2025/07/04 08:48:53 wiz Exp $

DISTNAME=	Time-Progress-2.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Time-Progress
COMMENT=	Elapsed and estimated finish time reporting
LICENSE=	${PERL5_LICENSE} # see README

PERL5_PACKLIST=		auto/Time/Progress/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
