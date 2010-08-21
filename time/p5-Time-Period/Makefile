# $NetBSD: Makefile,v 1.14 2010/08/21 16:36:28 seb Exp $

DISTNAME=	Period-1.20
PKGNAME=	p5-Time-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5per
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PR/PRYAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module to deal with time periods

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Time/Period/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
