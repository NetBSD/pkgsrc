# $NetBSD: Makefile,v 1.4 2011/08/14 15:28:49 obache Exp $

DISTNAME=	Time-Warp-0.5
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Warp/
COMMENT=	Perl 5 module to control the flow of time

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Time/Warp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
