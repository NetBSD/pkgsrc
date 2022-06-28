# $NetBSD: Makefile,v 1.17 2022/06/28 11:36:53 wiz Exp $

DISTNAME=	DateTime-Event-Random-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FG/FGLOCK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Event-Random
COMMENT=	DateTime extension for creating random datetimes

DEPENDS+=	p5-DateTime>0:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Set>=0.07:../../time/p5-DateTime-Set

PERL5_PACKLIST=	auto/DateTime/Event/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
