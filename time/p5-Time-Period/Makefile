# $NetBSD: Makefile,v 1.15 2011/08/14 15:28:49 obache Exp $

DISTNAME=	Period-1.20
PKGNAME=	p5-Time-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5per
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PR/PRYAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module to deal with time periods

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Time/Period/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
