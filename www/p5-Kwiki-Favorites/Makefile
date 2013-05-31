# $NetBSD: Makefile,v 1.15 2013/05/31 12:42:46 wiz Exp $

DISTNAME=	Kwiki-Favorites-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki plugin to bookmark favorite pages

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki

PERL5_PACKLIST=	auto/Kwiki/Favorites/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
