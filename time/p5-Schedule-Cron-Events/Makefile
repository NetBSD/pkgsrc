# $NetBSD: Makefile,v 1.3 2005/08/06 06:19:35 jlam Exp $

DISTNAME=	Schedule-Cron-Events-1.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Schedule/}

MAINTAINER=	epg@NetBSD.org
COMMENT=	Perl module to find when crontab events will occur

PKG_INSTALLATION_TYPES= overwrite pkgviews

PERL5_PACKLIST=	auto/Schedule/Cron/Events/.packlist

DEPENDS+=	p5-Set-Crontab>=1.00:../../math/p5-Set-Crontab

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
