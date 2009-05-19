# $NetBSD: Makefile,v 1.10 2009/05/19 23:27:34 sno Exp $

DISTNAME=	Time-Piece-1.14
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tpc
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Piece/
COMMENT=	Time::Piece - Object Oriented time objects
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c

PERL5_PACKLIST=		auto/Time/Piece/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
