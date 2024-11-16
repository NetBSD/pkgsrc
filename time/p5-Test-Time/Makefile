# $NetBSD: Makefile,v 1.19 2024/11/16 12:07:22 wiz Exp $

DISTNAME=	Test-Time-0.092
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Time
COMMENT=	Override time()/sleep() core functions for testing
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp

PERL5_PACKLIST=	auto/Test/Time/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
