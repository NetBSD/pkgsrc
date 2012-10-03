# $NetBSD: Makefile,v 1.9 2012/10/03 21:58:22 wiz Exp $

DISTNAME=	Schedule-Cron-Events-1.8
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Schedule/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module to find when crontab events will occur

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Schedule/Cron/Events/.packlist

DEPENDS+=	p5-Set-Crontab>=1.00:../../math/p5-Set-Crontab

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
