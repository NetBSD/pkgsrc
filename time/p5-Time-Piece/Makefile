# $NetBSD: Makefile,v 1.4 2005/07/13 18:01:45 jlam Exp $

DISTNAME=	Time-Piece-1.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tpc
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Time-Piece/
COMMENT=	Time::Piece - Object Oriented time objects

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Time/Piece/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
