# $NetBSD: Makefile,v 1.1.1.1 2008/09/10 16:48:52 seb Exp $

DISTNAME=	Time-Warp-0.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Warp/
COMMENT=	Perl 5 module to control the flow of time

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Time/Warp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
