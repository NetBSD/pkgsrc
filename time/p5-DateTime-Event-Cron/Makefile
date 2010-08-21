# $NetBSD: Makefile,v 1.8 2010/08/21 16:36:21 seb Exp $

DISTNAME=	DateTime-Event-Cron-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Event-Cron/
COMMENT=	DateTime extension to handle crontab entries

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DateTime-Set>=0.19:../../time/p5-DateTime-Set
DEPENDS+=	p5-Set-Crontab-[0-9]*:../../math/p5-Set-Crontab

PERL5_PACKLIST=	auto/DateTime/Event/Cron/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
