# $NetBSD: Makefile,v 1.1.1.1 2005/05/06 19:47:31 epg Exp $

DISTNAME=	Schedule-Cron-Events-1.8
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Schedule/}

MAINTAINER=	epg@NetBSD.org
COMMENT=	Perl module to find when crontab events will occur

PKG_INSTALLATION_TYPES= overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Schedule/Cron/Events/.packlist

DEPENDS+=	p5-Set-Crontab>=1.00:../../math/p5-Set-Crontab

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
