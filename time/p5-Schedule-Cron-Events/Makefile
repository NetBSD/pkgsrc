# $NetBSD: Makefile,v 1.16 2016/06/08 19:24:51 wiz Exp $

DISTNAME=	Schedule-Cron-Events-1.93
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Schedule/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module to find when crontab events will occur
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Schedule/Cron/Events/.packlist

DEPENDS+=	p5-Set-Crontab>=1.00:../../math/p5-Set-Crontab

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
