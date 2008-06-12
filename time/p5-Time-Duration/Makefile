# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:52 joerg Exp $

DISTNAME=      	Time-Duration-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5 time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~avif/Time-Duration-1.04/Duration.pm
COMMENT=	Perl5 module for rounded or exact English expression of durations

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Time/Duration/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
