# $NetBSD: Makefile,v 1.26 2023/07/06 09:42:10 wiz Exp $

DISTNAME=	DateTime-Event-Cron-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Event-Cron
COMMENT=	DateTime extension to handle crontab entries
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-Set>=0.19:../../time/p5-DateTime-Set
DEPENDS+=	p5-Set-Crontab-[0-9]*:../../math/p5-Set-Crontab

PERL5_PACKLIST=	auto/DateTime/Event/Cron/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
