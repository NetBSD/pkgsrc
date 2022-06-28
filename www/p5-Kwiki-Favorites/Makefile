# $NetBSD: Makefile,v 1.26 2022/06/28 11:37:33 wiz Exp $

DISTNAME=	Kwiki-Favorites-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki plugin to bookmark favorite pages

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki

PERL5_PACKLIST=	auto/Kwiki/Favorites/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
