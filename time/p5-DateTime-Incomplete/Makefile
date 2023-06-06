# $NetBSD: Makefile,v 1.12 2023/06/06 12:42:36 riastradh Exp $

DISTNAME=	DateTime-Incomplete-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FG/FGLOCK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/DateTime::Incomplete
COMMENT=	DateTime::Incomplete - An incomplete datetime, like January 5
LICENSE=	${PERL5_LICENSE}

# for make test
TOOL_DEPENDS+=	p5-DateTime-Set-[0-9]*:../../time/p5-DateTime-Set
TOOL_DEPENDS+=	p5-DateTime-Event-Recurrence-[0-9]*:../../time/p5-DateTime-Event-Recurrence

PERL5_PACKLIST=	auto/DateTime/Incomplete/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
