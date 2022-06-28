# $NetBSD: Makefile,v 1.23 2022/06/28 11:36:47 wiz Exp $

DISTNAME=	iCal-Parser-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RI/RIXED/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/iCal-Parser
COMMENT=	Parse iCalendar files into a data structure
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-Format-ICal>=0.08:../../time/p5-DateTime-Format-ICal
DEPENDS+=	p5-Text-vFile-asData>=0.02:../../textproc/p5-Text-vFile-asData
DEPENDS+=	p5-FreezeThaw>=0.43:../../devel/p5-FreezeThaw
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String

PERL5_PACKLIST=	auto/iCal/Parser/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
