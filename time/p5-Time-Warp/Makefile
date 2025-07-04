# $NetBSD: Makefile,v 1.25 2025/07/04 08:48:54 wiz Exp $

DISTNAME=	Time-Warp-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Time-Warp
COMMENT=	Perl 5 module to control the flow of time
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Time/Warp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
