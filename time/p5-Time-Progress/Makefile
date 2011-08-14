# $NetBSD: Makefile,v 1.6 2011/08/14 15:28:49 obache Exp $

DISTNAME=	Time-Progress-1.7
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Progress/
COMMENT=	Elapsed and estimated finish time reporting
LICENSE=	${PERL5_LICENSE} # see README

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Time/Progress/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
